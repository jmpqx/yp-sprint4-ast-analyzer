#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

using SumAverageCountParametersFixture =
    AccumulatorFixture<SumAverageAccumulator, metric::metric_impl::CountParametersMetric>;
using SumAverageCodeLinesFixture = AccumulatorFixture<SumAverageAccumulator, metric::metric_impl::CodeLinesCountMetric>;
using SumAverageCyclomaticComplexityFixture =
    AccumulatorFixture<SumAverageAccumulator, metric::metric_impl::CyclomaticComplexityMetric>;
using SumAverageCountParametersFixtureTenFiles =
    AccumulatorFixture<SumAverageAccumulator, metric::metric_impl::CountParametersMetric, 10>;
using SumAverageCodeLinesFixtureTenFiles =
    AccumulatorFixture<SumAverageAccumulator, metric::metric_impl::CodeLinesCountMetric, 10>;
using SumAverageCyclomaticComplexityFixtureTenFiles =
    AccumulatorFixture<SumAverageAccumulator, metric::metric_impl::CyclomaticComplexityMetric, 10>;

TEST_F(SumAverageCountParametersFixture, SumAndAverageParametersCount) {
    ASSERT_EQ(result.sum, 29);
    ASSERT_NEAR(result.average, 29.0 / 14.0, 0.01);
}

TEST_F(SumAverageCountParametersFixtureTenFiles, SumAndAverageParametersCountWithoutSample) {
    ASSERT_EQ(result.sum, 14);
    ASSERT_NEAR(result.average, 1.4, 0.01);
}

TEST_F(SumAverageCodeLinesFixture, SumAndAverageCodeLinesCount) {
    ASSERT_EQ(result.sum, 65);
    ASSERT_NEAR(result.average, 65.0 / 14.0, 0.01);
}

TEST_F(SumAverageCodeLinesFixtureTenFiles, SumAndAverageCodeLinesCountWithoutSample) {
    ASSERT_EQ(result.sum, 52);
    ASSERT_NEAR(result.average, 5.2, 0.01);
}

TEST_F(SumAverageCyclomaticComplexityFixture, SumAndAverageCyclomaticComplexity) {
    ASSERT_EQ(result.sum, 32);
    ASSERT_NEAR(result.average, 32.0 / 14.0, 0.01);
}

TEST_F(SumAverageCyclomaticComplexityFixtureTenFiles, SumAndAverageCyclomaticComplexityWithoutSample) {
    ASSERT_EQ(result.sum, 28);
    ASSERT_NEAR(result.average, 2.8, 0.01);
}

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
