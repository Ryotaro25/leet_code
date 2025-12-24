class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, new_color: int) -> List[List[int]]:
        def fill_adjacent(row: int, col: int, target_color: int) -> None:
            if row < 0 or row >= len(image) or col < 0 or col >= len(image[0]):
                return
            if image[row][col] != target_color:
                return
            if image[row][col] == new_color:
                return
            image[row][col] = new_color
            next_rows = [-1, 0, 1, 0]
            next_cols = [0, 1, 0, -1]
            for i in range(4):
                fill_adjacent(row + next_rows[i], col + next_cols[i], target_color)

        if not image or not image[0]:
            return []

        for row in range(len(image)):
            for col in range(len(image[0])):
                if row == sr and col == sc:
                    fill_adjacent(row, col, image[row][col])
        return image