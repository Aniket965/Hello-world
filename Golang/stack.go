// Package stack creates a ItemStack data structure for the Item type
package stack

import (
    "sync"

    "github.com/cheekybits/genny/generic"
)

// Item the type of the stack
type Item generic.Type

// ItemStack the stack of Items
type ItemStack struct {
    items []Item
    lock  sync.RWMutex
}

// New creates a new ItemStack
func (s *ItemStack) New() *ItemStack {
    s.items = []Item{}
    return s
}

// Push adds an Item to the top of the stack
func (s *ItemStack) Push(t Item) {
    s.lock.Lock()
    s.items = append(s.items, t)
    s.lock.Unlock()
}

// Pop removes an Item from the top of the stack
func (s *ItemStack) Pop() *Item {
    s.lock.Lock()
    item := s.items[len(s.items)-1]
    s.items = s.items[0 : len(s.items)-1]
    s.lock.Unlock()
    return &item
}