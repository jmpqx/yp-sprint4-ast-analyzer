#include "metric_impl/cyclomatic_complexity.hpp"
#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

TEST(CyclomaticComplexityMetric, Comments) {
    MetricFixture<CyclomaticComplexityMetric> fixture("comments.py");
    ASSERT_EQ(fixture.GetResult("Func_comments"), 1);
}

TEST(CyclomaticComplexityMetric, If) {
    MetricFixture<CyclomaticComplexityMetric> fixture("if.py");
    ASSERT_EQ(fixture.GetResult("testIf"), 2);
}

TEST(CyclomaticComplexityMetric, Loops) {
    MetricFixture<CyclomaticComplexityMetric> fixture("loops.py");
    ASSERT_EQ(fixture.GetResult("TestLoops"), 4);
}

TEST(CyclomaticComplexityMetric, NestedIf) {
    MetricFixture<CyclomaticComplexityMetric> fixture("nested_if.py");
    ASSERT_EQ(fixture.GetResult("Testnestedif"), 4);
}

TEST(CyclomaticComplexityMetric, Ternary) {
    MetricFixture<CyclomaticComplexityMetric> fixture("ternary.py");
    ASSERT_EQ(fixture.GetResult("teSt_ternary"), 3);
}

TEST(CyclomaticComplexityMetric, Exceptions) {
    MetricFixture<CyclomaticComplexityMetric> fixture("exceptions.py");
    ASSERT_EQ(fixture.GetResult("Try_Exceptions"), 4);
}

TEST(CyclomaticComplexityMetric, MatchCase) {
    MetricFixture<CyclomaticComplexityMetric> fixture("match_case.py");
    ASSERT_EQ(fixture.GetResult("test_Match_case"), 4);
}

TEST(CyclomaticComplexityMetric, ManyParameters) {
    MetricFixture<CyclomaticComplexityMetric> fixture("many_parameters.py");
    ASSERT_EQ(fixture.GetResult("__test_multiparameters__"), 2);
}

TEST(CyclomaticComplexityMetric, ManyLines) {
    MetricFixture<CyclomaticComplexityMetric> fixture("many_lines.py");
    ASSERT_EQ(fixture.GetResult("testmultiline"), 2);
}

TEST(CyclomaticComplexityMetric, Simple) {
    MetricFixture<CyclomaticComplexityMetric> fixture("simple.py");
    ASSERT_EQ(fixture.GetResult("test_simple"), 2);
}

TEST(CyclomaticComplexityMetric, Sample) {
    MetricFixture<CyclomaticComplexityMetric> fixture("../../../files/sample.py");
    ASSERT_EQ(fixture.GetResult("__init__"), 1);
    ASSERT_EQ(fixture.GetResult("process"), 1);
    ASSERT_EQ(fixture.GetResult("__call__"), 1);
    ASSERT_EQ(fixture.GetResult("lambda_demo"), 1);
}

}  // namespace analyzer::metric::metric_impl
