import pytest
from solution_trapping_rain_water import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]) == 6


def test_example_2(solution):
    assert solution.trap([4, 2, 0, 3, 2, 5]) == 9


def test_two_bars(solution):
    assert solution.trap([1, 2]) == 0


def test_all_zero(solution):
    assert solution.trap([0, 0, 0]) == 0


def test_ascending(solution):
    assert solution.trap([1, 2, 3, 4, 5]) == 0


def test_descending(solution):
    assert solution.trap([5, 4, 3, 2, 1]) == 0


def test_valley(solution):
    assert solution.trap([3, 0, 3]) == 3


def test_single_bar(solution):
    assert solution.trap([3]) == 0
