type CQueue struct {
    stack1, stack2 *list.List
}


func Constructor() CQueue {
    return CQueue {
        stack1: list.New(),
        stack2: list.New(),
    }
}


func (this *CQueue) AppendTail(value int)  {
    this.stack1.PushBack(value)
}


func (this *CQueue) DeleteHead() int {
    if (this.stack2.Len() == 0) {
        for (this.stack1.Len() != 0) {
            e := this.stack1.Remove(this.stack1.Back())
            this.stack2.PushBack(e.(int))
        }
    }
    if (this.stack2.Len() != 0) {
        e := this.stack2.Remove(this.stack2.Back())
        return e.(int)
    }

    return -1
}


/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */