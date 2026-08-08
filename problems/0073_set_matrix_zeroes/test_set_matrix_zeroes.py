import pytest
from solution_set_matrix_zeroes import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    solution.setZeroes(matrix)
    assert matrix == [[1, 0, 1], [0, 0, 0], [1, 0, 1]]


def test_example_2(solution):
    matrix = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
    solution.setZeroes(matrix)
    assert matrix == [[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]]


def test_no_zeroes(solution):
    matrix = [[1, 2], [3, 4]]
    solution.setZeroes(matrix)
    assert matrix == [[1, 2], [3, 4]]


def test_single_zero_first_position(solution):
    matrix = [[0, 1], [1, 1]]
    solution.setZeroes(matrix)
    assert matrix == [[0, 0], [0, 1]]


def test_all_zeroes(solution):
    matrix = [[0, 0], [0, 0]]
    solution.setZeroes(matrix)
    assert matrix == [[0, 0], [0, 0]]


def test_zero_in_last_column(solution):
    matrix = [[1, 0], [2, 3]]
    solution.setZeroes(matrix)
    assert matrix == [[0, 0], [2, 0]]


def test_single_row(solution):
    matrix = [[1, 0, 1]]
    solution.setZeroes(matrix)
    assert matrix == [[0, 0, 0]]