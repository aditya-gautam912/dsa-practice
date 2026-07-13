import pytest
from solution_search_rotated import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.search([4, 5, 6, 7, 0, 1, 2], 0) == 4


def test_example_2(solution):
    assert solution.search([4, 5, 6, 7, 0, 1, 2], 3) == -1


def test_example_3(solution):
    assert solution.search([1], 0) == -1


def test_target_at_start(solution):
    assert solution.search([3, 4, 5, 1, 2], 3) == 0


def test_target_at_end(solution):
    assert solution.search([3, 4, 5, 1, 2], 2) == 4


def test_not_rotated(solution):
    assert solution.search([1, 2, 3, 4, 5], 3) == 2


def test_two_elements(solution):
    assert solution.search([2, 1], 1) == 1


def test_single_element_found(solution):
    assert solution.search([5], 5) == 0
