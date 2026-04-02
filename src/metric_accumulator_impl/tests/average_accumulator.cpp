#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

using CountParametersFixture = AccumulatorFixture<AverageAccumulator, metric::metric_impl::CountParametersMetric>;
using CodeLinesFixture = AccumulatorFixture<AverageAccumulator, metric::metric_impl::CodeLinesCountMetric>;
using CyclomaticComplexityFixture =
    AccumulatorFixture<AverageAccumulator, metric::metric_impl::CyclomaticComplexityMetric>;
using CountParametersFixtureTenFiles =
    AccumulatorFixture<AverageAccumulator, metric::metric_impl::CountParametersMetric, 10>;
using CodeLinesFixtureTenFiles = AccumulatorFixture<AverageAccumulator, metric::metric_impl::CodeLinesCountMetric, 10>;
using CyclomaticComplexityFixtureTenFiles =
    AccumulatorFixture<AverageAccumulator, metric::metric_impl::CyclomaticComplexityMetric, 10>;

TEST_F(CountParametersFixture, AverageParametersCount) { ASSERT_NEAR(result, 29.0 / 14.0, 0.01); }

TEST_F(CountParametersFixtureTenFiles, AverageParametersCountWithoutSample) { ASSERT_NEAR(result, 1.4, 0.01); }

TEST_F(CodeLinesFixture, AverageCodeLinesCount) { ASSERT_NEAR(result, 65.0 / 14.0, 0.01); }

TEST_F(CodeLinesFixtureTenFiles, AverageCodeLinesCountWithoutSample) { ASSERT_NEAR(result, 5.2, 0.01); }

TEST_F(CyclomaticComplexityFixture, AverageCyclomaticComplexity) { ASSERT_NEAR(result, 32.0 / 14.0, 0.01); }

TEST_F(CyclomaticComplexityFixtureTenFiles, AverageCyclomaticComplexityWithoutSample) {
    ASSERT_NEAR(result, 2.8, 0.01);
}

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
