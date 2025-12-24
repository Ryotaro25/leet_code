class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        def fill_adjacent(row: int, col: int, original_color: int) -> None:
            if row < 0 or row >= len(image) or col < 0 or col >= len(image[0]):
                return
            if image[row][col] != original_color:
                return
            if image[row][col] == color:
                return
            image[row][col] = color
            fill_adjacent(row - 1, col, original_color)
            fill_adjacent(row, col + 1, original_color)
            fill_adjacent(row + 1, col, original_color)
            fill_adjacent(row, col - 1, original_color)
            
        if not image or not image[0]:
            return []

        for row in range(len(image)):
            for col in range(len(image[0])):
                if row == sr and col == sc:
                    fill_adjacent(row, col, image[row][col])
        return image