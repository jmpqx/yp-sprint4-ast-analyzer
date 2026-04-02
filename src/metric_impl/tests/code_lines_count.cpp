#include "metric_impl/code_lines_count.hpp"
#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

TEST(CodeLinesCountMetric, Comments) {
    MetricFixture<CodeLinesCountMetric> fixture("comments.py");
    ASSERT_EQ(fixture.GetResult("Func_comments"), 3);
}

TEST(CodeLinesCountMetric, If) {
    MetricFixture<CodeLinesCountMetric> fixture("if.py");
    ASSERT_EQ(fixture.GetResult("testIf"), 3);
}

TEST(CodeLinesCountMetric, Loops) {
    MetricFixture<CodeLinesCountMetric> fixture("loops.py");
    ASSERT_EQ(fixture.GetResult("TestLoops"), 6);
}

TEST(CodeLinesCountMetric, NestedIf) {
    MetricFixture<CodeLinesCountMetric> fixture("nested_if.py");
    ASSERT_EQ(fixture.GetResult("Testnestedif"), 8);
}

TEST(CodeLinesCountMetric, Ternary) {
    MetricFixture<CodeLinesCountMetric> fixture("ternary.py");
    ASSERT_EQ(fixture.GetResult("teSt_ternary"), 1);
}

TEST(CodeLinesCountMetric, Exceptions) {
    MetricFixture<CodeLinesCountMetric> fixture("exceptions.py");
    ASSERT_EQ(fixture.GetResult("Try_Exceptions"), 7);
}

TEST(CodeLinesCountMetric, MatchCase) {
    MetricFixture<CodeLinesCountMetric> fixture("match_case.py");
    ASSERT_EQ(fixture.GetResult("test_Match_case"), 7);
}

TEST(CodeLinesCountMetric, ManyParameters) {
    MetricFixture<CodeLinesCountMetric> fixture("many_parameters.py");
    ASSERT_EQ(fixture.GetResult("__test_multiparameters__"), 1);
}

TEST(CodeLinesCountMetric, ManyLines) {
    MetricFixture<CodeLinesCountMetric> fixture("many_lines.py");
    ASSERT_EQ(fixture.GetResult("testmultiline"), 11);
}

TEST(CodeLinesCountMetric, Simple) {
    MetricFixture<CodeLinesCountMetric> fixture("simple.py");
    ASSERT_EQ(fixture.GetResult("test_simple"), 5);
}

TEST(CodeLinesCountMetric, Sample) {
    MetricFixture<CodeLinesCountMetric> fixture("../../../files/sample.py");
    ASSERT_EQ(fixture.GetResult("__init__"), 2);
    ASSERT_EQ(fixture.GetResult("process"), 3);
    ASSERT_EQ(fixture.GetResult("__call__"), 2);
    ASSERT_EQ(fixture.GetResult("lambda_demo"), 6);
}

}  // namespace analyzer::metric::metric_impl
