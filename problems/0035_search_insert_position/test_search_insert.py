import pytest
from solution_search_insert import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.searchInsert([1, 3, 5, 6], 5) == 2


def test_example_2(solution):
    assert solution.searchInsert([1, 3, 5, 6], 2) == 1


def test_example_3(solution):
    assert solution.searchInsert([1, 3, 5, 6], 7) == 4


def test_insert_at_start(solution):
    assert solution.searchInsert([1, 3, 5, 6], 0) == 0


def test_single_element_found(solution):
    assert solution.searchInsert([3], 3) == 0


def test_single_element_not_found_less(solution):
    assert solution.searchInsert([3], 1) == 0


def test_single_element_not_found_greater(solution):
    assert solution.searchInsert([3], 5) == 1


def test_empty_array(solution):
    assert solution.searchInsert([], 5) == 0
