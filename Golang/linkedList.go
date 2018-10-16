// Package linkedlist creates a ItemLinkedList data structure for the Item type
package linkedlist

import (
    "fmt"
    "sync"

    "github.com/cheekybits/genny/generic"
)

// Item the type of the linked list
type Item generic.Type

// Node a single node that composes the list
type Node struct {
    content Item
    next    *Node
}

// ItemLinkedList the linked list of Items
type ItemLinkedList struct {
    head *Node
    size int
    lock sync.RWMutex
}

// Append adds an Item to the end of the linked list
func (ll *ItemLinkedList) Append(t Item) {
    ll.lock.Lock()
    node := Node{t, nil}
    if ll.head == nil {
        ll.head = &node
    } else {
        last := ll.head
        for {
            if last.next == nil {
                break
            }
            last = last.next
        }
        last.next = &node
    }
    ll.size++
    ll.lock.Unlock()
}

// Insert adds an Item at position i
func (ll *ItemLinkedList) Insert(i int, t Item) error {
    ll.lock.Lock()
    defer ll.lock.Unlock()
    if i < 0 || i > ll.size {
        return fmt.Errorf("Index out of bounds")
    }
    addNode := Node{t, nil}
    if i == 0 {
        addNode.next = ll.head
        ll.head = &addNode
        return nil
    }
    node := ll.head
    j := 0
    for j < i-2 {
        j++
        node = node.next
    }
    addNode.next = node.next
    node.next = &addNode
    ll.size++
    return nil
}

// RemoveAt removes a node at position i
func (ll *ItemLinkedList) RemoveAt(i int) (*Item, error) {
    ll.lock.Lock()
    defer ll.lock.Unlock()
    if i < 0 || i > ll.size {
        return nil, fmt.Errorf("Index out of bounds")
    }
    node := ll.head
    j := 0
    for j < i-1 {
        j++
        node = node.next
    }
    remove := node.next
    node.next = remove.next
    ll.size--
    return &remove.content, nil
}

// IndexOf returns the position of the Item t
func (ll *ItemLinkedList) IndexOf(t Item) int {
    ll.lock.RLock()
    defer ll.lock.RUnlock()
    node := ll.head
    j := 0
    for {
        if node.content == t {
            return j
        }
        if node.next == nil {
            return -1
        }
        node = node.next
        j++
    }
}

// IsEmpty returns true if the list is empty
func (ll *ItemLinkedList) IsEmpty() bool {
    ll.lock.RLock()
    defer ll.lock.RUnlock()
    if ll.head == nil {
        return true
    }
    return false
}

// Size returns the linked list size
func (ll *ItemLinkedList) Size() int {
    ll.lock.RLock()
    defer ll.lock.RUnlock()
    size := 1
    last := ll.head
    for {
        if last == nil || last.next == nil {
            break
        }
        last = last.next
        size++
    }
    return size
}

// Insert adds an Item at position i
func (ll *ItemLinkedList) String() {
    ll.lock.RLock()
    defer ll.lock.RUnlock()
    node := ll.head
    j := 0
    for {
        if node == nil {
            break
        }
        j++
        fmt.Print(node.content)
        fmt.Print(" ")
        node = node.next
    }
    fmt.Println()
}

// Head returns a pointer to the first node of the list
func (ll *ItemLinkedList) Head() *Node {
    ll.lock.RLock()
    defer ll.lock.RUnlock()
    return ll.head
}
