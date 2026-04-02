
#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

using NamingStyleFixture = AccumulatorFixture<CategoricalAccumulator, metric::metric_impl::NamingStyleMetric>;
using NamingStyleFixtureTenFiles =
    AccumulatorFixture<CategoricalAccumulator, metric::metric_impl::NamingStyleMetric, 10>;

TEST_F(NamingStyleFixture, NamingStyleFrequencies) {
    ASSERT_EQ(result.at("Snake Case"), 5);
    ASSERT_EQ(result.at("Lower Case"), 2);
    ASSERT_EQ(result.at("Pascal Case"), 2);
    ASSERT_EQ(result.at("Camel Case"), 1);
    ASSERT_EQ(result.at("Unknown"), 4);
    ASSERT_EQ(result.size(), 5);
}

TEST_F(NamingStyleFixtureTenFiles, NamingStyleFrequenciesWithoutSample) {
    ASSERT_EQ(result.at("Snake Case"), 2);
    ASSERT_EQ(result.at("Lower Case"), 1);
    ASSERT_EQ(result.at("Pascal Case"), 2);
    ASSERT_EQ(result.at("Camel Case"), 1);
    ASSERT_EQ(result.at("Unknown"), 4);
    ASSERT_EQ(result.size(), 5);
}

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
