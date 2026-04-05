#include "metric_impl/code_lines_count.hpp"
#include "test_fixture.hpp"

#include <gtest/gtest.h>

namespace analyzer::metric::metric_impl {

using CodeLinesCountFixture = MetricFixture<CodeLinesCountMetric>;

TEST_P(CodeLinesCountFixture, Test) {
    const auto &[func_name, file_name, expected] = GetParam();
    Init(file_name);
    ASSERT_EQ(GetResult(func_name), std::get<int>(expected));
}

INSTANTIATE_TEST_SUITE_P(CodeLinesCountTests, CodeLinesCountFixture, testing::Values(
    TestCase{"Func_comments", "comments.py", 3},
    TestCase{"testIf", "if.py", 3},
    TestCase{"TestLoops", "loops.py", 6},
    TestCase{"Testnestedif", "nested_if.py", 8},
    TestCase{"teSt_ternary", "ternary.py", 1},
    TestCase{"Try_Exceptions", "exceptions.py", 7},
    TestCase{"test_Match_case", "match_case.py", 7},
    TestCase{"__test_multiparameters__", "many_parameters.py", 1},
    TestCase{"testmultiline", "many_lines.py", 11},
    TestCase{"test_simple", "simple.py", 5}
));

}  // namespace analyzer::metric::metric_impl
