class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def traverse_island(row: int, col: int) -> None:
            if row < 0 or row >= len(grid) or col < 0 or col >= len(grid[0]):
                return
            if grid[row][col] == '0' or grid[row][col] == '2':
                return
            grid[row][col] = '2'
            traverse_island(row - 1, col)
            traverse_island(row, col + 1)
            traverse_island(row + 1, col)
            traverse_island(row, col - 1)

        if not grid:
            return 0

        num_island = 0
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] != '1':
                    continue
                num_island += 1
                traverse_island(row, col)
        return num_island
