import pytest
from solution_plus_one import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.plusOne([1, 2, 3]) == [1, 2, 4]


def test_example_2(solution):
    assert solution.plusOne([4, 3, 2, 1]) == [4, 3, 2, 2]


def test_example_3(solution):
    assert solution.plusOne([9]) == [1, 0]


def test_all_nines(solution):
    assert solution.plusOne([9, 9, 9]) == [1, 0, 0, 0]


def test_carry_in_middle(solution):
    assert solution.plusOne([1, 9, 9]) == [2, 0, 0]


def test_single_digit_no_carry(solution):
    assert solution.plusOne([7]) == [8]


def test_large_number(solution):
    assert solution.plusOne([9, 8, 7, 6, 5, 4, 3, 2, 1, 0]) == [9, 8, 7, 6, 5, 4, 3, 2, 1, 1]
