#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric_accumulator::metric_accumulator_impl::test {

using CountParametersFixture = AccumulatorFixture<AverageAccumulator, metric::metric_impl::CountParametersMetric>;
using CodeLinesFixture = AccumulatorFixture<AverageAccumulator, metric::metric_impl::CodeLinesCountMetric>;
using CyclomaticComplexityFixture =
    AccumulatorFixture<AverageAccumulator, metric::metric_impl::CyclomaticComplexityMetric>;
using CountParametersFixtureNineFiles =
    AccumulatorFixture<AverageAccumulator, metric::metric_impl::CountParametersMetric, 9>;
using CodeLinesFixtureNineFiles = AccumulatorFixture<AverageAccumulator, metric::metric_impl::CodeLinesCountMetric, 9>;
using CyclomaticComplexityFixtureNineFiles =
    AccumulatorFixture<AverageAccumulator, metric::metric_impl::CyclomaticComplexityMetric, 9>;

TEST_F(CountParametersFixture, AverageParametersCount) { ASSERT_NEAR(result, 14.0 / 10.0, 0.01); }

TEST_F(CountParametersFixtureNineFiles, AverageParametersCountWithoutLast) { ASSERT_NEAR(result, 14.0 / 9.0, 0.01); }

TEST_F(CodeLinesFixture, AverageCodeLinesCount) { ASSERT_NEAR(result, 52.0 / 10.0, 0.01); }

TEST_F(CodeLinesFixtureNineFiles, AverageCodeLinesCountWithoutLast) { ASSERT_NEAR(result, 47.0 / 9.0, 0.01); }

TEST_F(CyclomaticComplexityFixture, AverageCyclomaticComplexity) { ASSERT_NEAR(result, 28.0 / 10.0, 0.01); }

TEST_F(CyclomaticComplexityFixtureNineFiles, AverageCyclomaticComplexityWithoutLast) {
    ASSERT_NEAR(result, 26.0 / 9.0, 0.01);
}

}  // namespace analyzer::metric_accumulator::metric_accumulator_impl::test
