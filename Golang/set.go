// Package set creates a ItemSet data structure for the Item type
package set

import "github.com/cheekybits/genny/generic"

// Item the type of the Set
type Item generic.Type

// ItemSet the set of Items
type ItemSet struct {
    items map[Item]bool
}

// Add adds a new element to the Set. Returns a pointer to the Set.
func (s *ItemSet) Add(t Item) *ItemSet {
    if s.items == nil {
        s.items = make(map[Item]bool)
    }
    _, ok := s.items[t]
    if !ok {
        s.items[t] = true
    }
    return s
}

// Clear removes all elements from the Set
func (s *ItemSet) Clear() {
    s.items = make(map[Item]bool)
}

// Delete removes the Item from the Set and returns Has(Item)
func (s *ItemSet) Delete(item Item) bool {
    _, ok := s.items[item]
    if ok {
        delete(s.items, item)
    }
    return ok
}

// Has returns true if the Set contains the Item
func (s *ItemSet) Has(item Item) bool {
    _, ok := s.items[item]
    return ok
}

// Items returns the Item(s) stored
func (s *ItemSet) Items() []Item {
    items := []Item{}
    for i := range s.items {
        items = append(items, i)
    }
    return items
}

// Size returns the size of the set
func (s *ItemSet) Size() int {
    return len(s.items)
}