import pytest
from solution_find_first_last import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.searchRange([5, 7, 7, 8, 8, 10], 8) == [3, 4]


def test_example_2(solution):
    assert solution.searchRange([5, 7, 7, 8, 8, 10], 6) == [-1, -1]


def test_example_3(solution):
    assert solution.searchRange([], 0) == [-1, -1]


def test_single_element_found(solution):
    assert solution.searchRange([5], 5) == [0, 0]


def test_single_element_not_found(solution):
    assert solution.searchRange([5], 3) == [-1, -1]


def test_all_same(solution):
    assert solution.searchRange([2, 2, 2, 2], 2) == [0, 3]


def test_target_at_ends(solution):
    assert solution.searchRange([1, 2, 3, 4], 1) == [0, 0]
    assert solution.searchRange([1, 2, 3, 4], 4) == [3, 3]


def test_two_elements(solution):
    assert solution.searchRange([3, 3], 3) == [0, 1]
