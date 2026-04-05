#include "metric_impl/naming_style.hpp"
#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

using NamingStyleFixture = MetricFixture<NamingStyleMetric>;

TEST_P(NamingStyleFixture, Test) {
    const auto &[func_name, file_name, expected] = GetParam();
    Init(file_name);
    ASSERT_EQ(GetResult(func_name), std::get<std::string>(expected));
}

INSTANTIATE_TEST_SUITE_P(NamingStyleTests, NamingStyleFixture, testing::Values(
    TestCase{"Func_comments", "comments.py", "Unknown"},
    TestCase{"testIf", "if.py", "Camel Case"},
    TestCase{"TestLoops", "loops.py", "Pascal Case"},
    TestCase{"Testnestedif", "nested_if.py", "Pascal Case"},
    TestCase{"teSt_ternary", "ternary.py", "Unknown"},
    TestCase{"Try_Exceptions", "exceptions.py", "Unknown"},
    TestCase{"test_Match_case", "match_case.py", "Unknown"},
    TestCase{"__test_multiparameters__", "many_parameters.py", "Snake Case"},
    TestCase{"testmultiline", "many_lines.py", "Lower Case"},
    TestCase{"test_simple", "simple.py", "Snake Case"}
));

}  // namespace analyzer::metric::metric_impl
