func maxProfit(prices []int) int {
    if len(prices) <= 1 {
        return 0;
    }

    unhold := 0;
    freeze := 0
    hold := -prices[0]

    for _, price := range(prices) {
        _freeze := hold + price
        var _unhold int
        var _hold int

        if freeze > unhold {
            _unhold = freeze
        } else {
            _unhold = unhold
        }

        if hold > unhold - price {
            _hold = hold
        } else {
            _hold = unhold - price
        }

        hold = _hold
        unhold = _unhold
        freeze = _freeze
    }

    if (unhold > freeze) {
        return unhold;
    } else {
        return freeze;
    }
}