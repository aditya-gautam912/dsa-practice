import pytest
from solution_rotate_image import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    solution.rotate(matrix)
    assert matrix == [[7, 4, 1], [8, 5, 2], [9, 6, 3]]


def test_example_2(solution):
    matrix = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]
    solution.rotate(matrix)
    assert matrix == [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]]


def test_single_element(solution):
    matrix = [[1]]
    solution.rotate(matrix)
    assert matrix == [[1]]


def test_two_by_two(solution):
    matrix = [[1, 2], [3, 4]]
    solution.rotate(matrix)
    assert matrix == [[3, 1], [4, 2]]


def test_negative_numbers(solution):
    matrix = [[-1, -2], [-3, -4]]
    solution.rotate(matrix)
    assert matrix == [[-3, -1], [-4, -2]]


def test_rotate_twice(solution):
    matrix = [[1, 2], [3, 4]]
    solution.rotate(matrix)
    solution.rotate(matrix)
    assert matrix == [[4, 3], [2, 1]]
