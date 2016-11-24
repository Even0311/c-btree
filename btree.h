//
// Created by Haoran Zhi on 16/10/6.
//


#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <cstddef>
#include <utility>
#include<iterator>
#include<vector>
#include<queue>
#include<stack>
#include<memory>
#include<algorithm>

#include "btree_iterator.h"

template<typename T> class btree;
template<typename T> std::ostream &operator<<(std::ostream&, const btree<T>&);
template <typename T>
class btree {
public:

    friend class btree_iterator<T> ;
    friend class const_btree_iterator<T> ;
    typedef btree_iterator<T> iterator;
    typedef const_btree_iterator<T> const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    btree(size_t maxNodeElems = 40);
    btree(const btree<T>& rhs);
    btree(btree<T>&& rhs) noexcept ;
    btree<T>& operator=(const btree<T>& rhs);
    btree<T>& operator=(btree<T>&& rhs)noexcept ;
    ~btree() = default;
    friend std::ostream& operator<<<T> (std::ostream& os, const btree<T>& tree);
    iterator 				begin()const;
    iterator 				end()const;
    reverse_iterator 		rbegin() 	const;
    reverse_iterator 		rend() 		const;
    const_iterator 			cbegin() 	const;
    const_iterator 			cend() 		const;
    const_reverse_iterator 	crbegin() 	const;
    const_reverse_iterator 	crend() 	const;

    iterator find(const T& elem) ;
    const_iterator find(const T& elem) const;

    std::pair<iterator, bool> insert(const T& elem);






private:
    struct Node
    {

        Node(size_t maxNodeElems = 40) ;
        Node(const Node& rhs);
        Node(Node&& rhs) noexcept ;
        Node& operator=(const Node& rhs);
        Node& operator=(Node&& rhs)noexcept ;
        ~Node() = default ;
        bool have_successors() const;
        bool operator == (const Node& rhs) const;
        bool operator !=(const Node& rhs) const
        {
            return !(*this == rhs);
        };
        size_t maxNode;
        std::vector<T> elements;
        std::vector<std::shared_ptr<typename btree::Node>> successors;
        std::shared_ptr<typename btree::Node> father;

    };
    size_t maxNode;
    std::shared_ptr<typename btree<T>::Node> root;
    mutable std::shared_ptr<typename btree<T>::Node> head_node;
    mutable std::shared_ptr<typename btree<T>::Node> tail_node;
    mutable bool tree_is_changed;

    // helping functions
    void update()const;
    iterator help_find1(std::shared_ptr<typename btree<T>::Node>, const T&);
    const_iterator help_find2(std::shared_ptr<typename btree<T>::Node>, const T&) const;
    std::pair<typename btree<T>::iterator,bool> help_insert(std::shared_ptr<typename btree<T>::Node>,size_t ,const T&);
};

#include"btree.tem"

/*
 * Here I know this big 5 is wrong because what am I doing here is not a
 * deep copy , but I tried deep copy , I was failed because
 * I do not know how to consturct a raw pointer , specifically "this" into a smart pointer
 *
 * And I send you an email, you have not respond me , there are several times that you did not respond my email
 * which are all very important questions that I cannot solve
 *
 *
 * That is okay , anyway this is my fault .
 *
 *
 *
 * So I can only do a not deep copy here ...
 */
// constructor of btree

#endif 
