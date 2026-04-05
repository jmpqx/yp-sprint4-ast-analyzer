#pragma once

#include "metric_impl/metrics.hpp"

#include <gtest/gtest.h>
#include <string>
#include <unordered_map>

namespace analyzer::metric::metric_impl {

using TestCase = std::tuple<std::string, std::string, std::variant<int, std::string>>;

template <typename MetricType>
class MetricFixture : public testing::TestWithParam<TestCase> {
public:
    using FunctionNameMetricResult = std::pair<std::string, MetricResult>;
    using FixtureResults = std::unordered_map<std::string, MetricResult>;

    MetricFixture() = default;

    void Init(const std::string &filename) {
        file::File test_file(filename);
        auto functions = function::FunctionExtractor{}.Get(test_file);
        auto metric = MetricType{};
        _results = std::views::all(functions) | std::views::transform([&](auto &&function) {
                       return std::make_pair(function.name, metric.Calculate(function));
                   }) | std::ranges::to<FixtureResults>();
    }

    auto GetResult(const std::string &function_name) const {
        if constexpr (std::same_as<MetricType, NamingStyleMetric>) {
            return std::get<std::string>(_results.at(function_name).value);
        }
        else {
            return std::get<int>(_results.at(function_name).value);
        }
    }

private:
    FixtureResults _results;
};

}  // namespace analyzer::metric::metric_impl
