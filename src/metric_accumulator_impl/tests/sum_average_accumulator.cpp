#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

using SumAverageCountParametersFixture =
    AccumulatorFixture<SumAverageAccumulator, metric::metric_impl::CountParametersMetric>;
using SumAverageCodeLinesFixture = AccumulatorFixture<SumAverageAccumulator, metric::metric_impl::CodeLinesCountMetric>;
using SumAverageCyclomaticComplexityFixture =
    AccumulatorFixture<SumAverageAccumulator, metric::metric_impl::CyclomaticComplexityMetric>;
using SumAverageCountParametersFixtureNineFiles =
    AccumulatorFixture<SumAverageAccumulator, metric::metric_impl::CountParametersMetric, 9>;
using SumAverageCodeLinesFixtureNineFiles =
    AccumulatorFixture<SumAverageAccumulator, metric::metric_impl::CodeLinesCountMetric, 9>;
using SumAverageCyclomaticComplexityFixtureNineFiles =
    AccumulatorFixture<SumAverageAccumulator, metric::metric_impl::CyclomaticComplexityMetric, 9>;

TEST_F(SumAverageCountParametersFixture, SumAndAverageParametersCount) {
    ASSERT_EQ(result.sum, 14);
    ASSERT_NEAR(result.average, 14.0 / 10.0, 0.01);
}

TEST_F(SumAverageCountParametersFixtureNineFiles, SumAndAverageParametersCountWithoutLast) {
    ASSERT_EQ(result.sum, 14);
    ASSERT_NEAR(result.average, 14.0 / 9.0, 0.01);
}

TEST_F(SumAverageCodeLinesFixture, SumAndAverageCodeLinesCount) {
    ASSERT_EQ(result.sum, 52);
    ASSERT_NEAR(result.average, 52.0 / 10.0, 0.01);
}

TEST_F(SumAverageCodeLinesFixtureNineFiles, SumAndAverageCodeLinesCountWithoutLast) {
    ASSERT_EQ(result.sum, 47);
    ASSERT_NEAR(result.average, 47.0 / 9.0, 0.01);
}

TEST_F(SumAverageCyclomaticComplexityFixture, SumAndAverageCyclomaticComplexity) {
    ASSERT_EQ(result.sum, 28);
    ASSERT_NEAR(result.average, 28.0 / 10.0, 0.01);
}

TEST_F(SumAverageCyclomaticComplexityFixtureNineFiles, SumAndAverageCyclomaticComplexityWithoutLast) {
    ASSERT_EQ(result.sum, 26);
    ASSERT_NEAR(result.average, 26.0 / 9.0, 0.01);
}

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
