class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def traverse_island(grid: List[List[str]], row: int, col: int) -> None:
            if row < 0 or row >= len(grid) or col < 0 or col >= len(grid[0]):
                return
            if grid[row][col] == '0':
                return
            grid[row][col] = '0'
            row_directions = [-1, 0, 1, 0]
            col_directions = [0, 1, 0, -1]
            for i in range(4):
                next_row = row + row_directions[i]
                next_col = col + col_directions[i]
                traverse_island(grid, next_row, next_col)

        if not grid:
            return 0
        num_island = 0
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] != '1':
                    continue
                num_island += 1
                traverse_island(grid, row, col)
        return num_island

    

