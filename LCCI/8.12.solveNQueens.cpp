func solveNQueens(n int) [][]string {
   var results [][]string
   if n <= 0 {
      return results
   }
   search(&results, []int{}, n)
   return results
}

func search(results *[][]string, cols []int, n int) {
   if len(cols) == n {
      *results = append(*results, drawChessboard(cols))
      return
   }
   for colIndex := 0; colIndex < n; colIndex++ {
      if !isValid(cols, colIndex) {
         continue
      }
      cols = append(cols, colIndex)
      search(results, cols, n)
      cols = cols[:len(cols)-1]
   }
}

func drawChessboard(cols []int) []string {
   var chessboard []string
   for i := 0; i < len(cols); i++ {
      var row string
      for j := 0; j < len(cols); j++ {
         if j == cols[i] {
            row += "Q"
         } else {
            row += "."
         }
      }
      chessboard = append(chessboard, row)
   }
   return chessboard
}

func isValid(cols []int, column int) bool {
   row := len(cols)
   for rowIndex := 0; rowIndex < len(cols); rowIndex++ {
      if cols[rowIndex] == column {
         return false
      }
      if rowIndex+cols[rowIndex] == row+column {
         return false
      }
      if rowIndex-cols[rowIndex] == row-column {
         return false
      }
   }
   return true
}