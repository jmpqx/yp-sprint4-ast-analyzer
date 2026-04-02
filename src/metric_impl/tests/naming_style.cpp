#include "metric_impl/naming_style.hpp"
#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

TEST(NamingStyleMetric, Comments) {
    MetricFixture<NamingStyleMetric> fixture("comments.py");
    ASSERT_EQ(fixture.GetResult("Func_comments"), "Unknown");
}

TEST(NamingStyleMetric, If) {
    MetricFixture<NamingStyleMetric> fixture("if.py");
    ASSERT_EQ(fixture.GetResult("testIf"), "Camel Case");
}

TEST(NamingStyleMetric, Loops) {
    MetricFixture<NamingStyleMetric> fixture("loops.py");
    ASSERT_EQ(fixture.GetResult("TestLoops"), "Pascal Case");
}

TEST(NamingStyleMetric, NestedIf) {
    MetricFixture<NamingStyleMetric> fixture("nested_if.py");
    ASSERT_EQ(fixture.GetResult("Testnestedif"), "Pascal Case");
}

TEST(NamingStyleMetric, Ternary) {
    MetricFixture<NamingStyleMetric> fixture("ternary.py");
    ASSERT_EQ(fixture.GetResult("teSt_ternary"), "Unknown");
}

TEST(NamingStyleMetric, Exceptions) {
    MetricFixture<NamingStyleMetric> fixture("exceptions.py");
    ASSERT_EQ(fixture.GetResult("Try_Exceptions"), "Unknown");
}

TEST(NamingStyleMetric, MatchCase) {
    MetricFixture<NamingStyleMetric> fixture("match_case.py");
    ASSERT_EQ(fixture.GetResult("test_Match_case"), "Unknown");
}

TEST(NamingStyleMetric, ManyParameters) {
    MetricFixture<NamingStyleMetric> fixture("many_parameters.py");
    ASSERT_EQ(fixture.GetResult("__test_multiparameters__"), "Snake Case");
}

TEST(NamingStyleMetric, ManyLines) {
    MetricFixture<NamingStyleMetric> fixture("many_lines.py");
    ASSERT_EQ(fixture.GetResult("testmultiline"), "Lower Case");
}

TEST(NamingStyleMetric, Simple) {
    MetricFixture<NamingStyleMetric> fixture("simple.py");
    ASSERT_EQ(fixture.GetResult("test_simple"), "Snake Case");
}

TEST(NamingStyleMetric, Sample) {
    MetricFixture<NamingStyleMetric> fixture("../../../files/sample.py");
    ASSERT_EQ(fixture.GetResult("__init__"), "Snake Case");
    ASSERT_EQ(fixture.GetResult("process"), "Lower Case");
    ASSERT_EQ(fixture.GetResult("__call__"), "Snake Case");
    ASSERT_EQ(fixture.GetResult("lambda_demo"), "Snake Case");
}

}  // namespace analyzer::metric::metric_impl
