func corpFlightBookings(bookings [][]int, n int) []int {
    arr := make([]int , n+2)
    for _, book := range bookings {
        arr[book[0]] += book[2]
        arr[book[1]+1] -= book[2]
    }
    for i := 1; i <= n; i++ {
        arr[i] += arr[i-1]
    }
    return arr[1:n+1]
}
