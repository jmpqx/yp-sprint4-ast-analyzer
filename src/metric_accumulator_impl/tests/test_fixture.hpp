#pragma once

#include <gtest/gtest.h>
#include <string>

#include "analyse.hpp"
#include "metric_accumulator_impl/accumulators.hpp"
#include "metric_impl/metrics.hpp"

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

static const size_t kFilesListSize = 11;
static const std::vector<std::string> kFilesList = {"../metric_impl/comments.py",   "../metric_impl/if.py",
                                                    "../metric_impl/loops.py",      "../metric_impl/nested_if.py",
                                                    "../metric_impl/ternary.py",    "../metric_impl/exceptions.py",
                                                    "../metric_impl/match_case.py", "../metric_impl/many_parameters.py",
                                                    "../metric_impl/many_lines.py", "../metric_impl/simple.py",
                                                    "../metric_impl/sample.py"};

template <typename AccumulatorType, typename MetricType, size_t N = kFilesListSize>
class AccumulatorFixture : public ::testing::Test {
protected:
    void SetUp() override {
        metric::MetricExtractor metric_extractor;
        metric_extractor.RegisterMetric(std::make_unique<MetricType>());

        auto analysis = analyzer::AnalyzeFunctions(
            std::vector<std::string>(kFilesList.begin(), std::next(kFilesList.begin(), N)), metric_extractor);

        metric_accumulator::MetricsAccumulator accumulator;
        accumulator.RegisterAccumulator(MetricType::kName, std::make_unique<AccumulatorType>());

        analyzer::AccumulateFunctionAnalysis(analysis, accumulator);
        result = accumulator.template GetFinalizedAccumulator<AccumulatorType>(MetricType::kName).Get();
    }

public:
    std::remove_cvref_t<decltype(std::declval<AccumulatorType>().Get())> result;
};
}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
