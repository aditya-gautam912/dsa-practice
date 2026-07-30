import pytest
from solution_first_missing_positive import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.firstMissingPositive([1, 2, 0]) == 3


def test_example_2(solution):
    assert solution.firstMissingPositive([3, 4, -1, 1]) == 2


def test_example_3(solution):
    assert solution.firstMissingPositive([7, 8, 9, 11, 12]) == 1


def test_single_element_missing(solution):
    assert solution.firstMissingPositive([2]) == 1


def test_single_element_present(solution):
    assert solution.firstMissingPositive([1]) == 2


def test_all_negative(solution):
    assert solution.firstMissingPositive([-1, -2, -3]) == 1


def test_all_positive_consecutive(solution):
    assert solution.firstMissingPositive([1, 2, 3]) == 4


def test_with_duplicates(solution):
    assert solution.firstMissingPositive([1, 1, 2, 3]) == 4


def test_large_gap(solution):
    assert solution.firstMissingPositive([1, 100, 200]) == 2
