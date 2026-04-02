#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

TEST(CountParametersMetric, Comments) {
    MetricFixture<CountParametersMetric> fixture("comments.py");
    ASSERT_EQ(fixture.GetResult("Func_comments"), 3);
}

TEST(CountParametersMetric, If) {
    MetricFixture<CountParametersMetric> fixture("if.py");
    ASSERT_EQ(fixture.GetResult("testIf"), 1);
}

TEST(CountParametersMetric, Loops) {
    MetricFixture<CountParametersMetric> fixture("loops.py");
    ASSERT_EQ(fixture.GetResult("TestLoops"), 1);
}

TEST(CountParametersMetric, NestedIf) {
    MetricFixture<CountParametersMetric> fixture("nested_if.py");
    ASSERT_EQ(fixture.GetResult("Testnestedif"), 2);
}

TEST(CountParametersMetric, Ternary) {
    MetricFixture<CountParametersMetric> fixture("ternary.py");
    ASSERT_EQ(fixture.GetResult("teSt_ternary"), 1);
}

TEST(CountParametersMetric, Exceptions) {
    MetricFixture<CountParametersMetric> fixture("exceptions.py");
    ASSERT_EQ(fixture.GetResult("Try_Exceptions"), 0);
}

TEST(CountParametersMetric, MatchCase) {
    MetricFixture<CountParametersMetric> fixture("match_case.py");
    ASSERT_EQ(fixture.GetResult("test_Match_case"), 1);
}

TEST(CountParametersMetric, ManyParameters) {
    MetricFixture<CountParametersMetric> fixture("many_parameters.py");
    ASSERT_EQ(fixture.GetResult("__test_multiparameters__"), 5);
}

TEST(CountParametersMetric, ManyLines) {
    MetricFixture<CountParametersMetric> fixture("many_lines.py");
    ASSERT_EQ(fixture.GetResult("testmultiline"), 0);
}

TEST(CountParametersMetric, Simple) {
    MetricFixture<CountParametersMetric> fixture("simple.py");
    ASSERT_EQ(fixture.GetResult("test_simple"), 0);
}

TEST(CountParametersMetric, Sample) {
    MetricFixture<CountParametersMetric> fixture("../../../files/sample.py");
    ASSERT_EQ(fixture.GetResult("__init__"), 5);
    ASSERT_EQ(fixture.GetResult("process"), 6);
    ASSERT_EQ(fixture.GetResult("__call__"), 4);
    ASSERT_EQ(fixture.GetResult("lambda_demo"), 0);
}

}  // namespace analyzer::metric::metric_impl
