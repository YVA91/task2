#include <iostream>
#include "Catch2/src/catch2/catch_session.hpp"
#include "Catch2/src/catch2/catch_test_macros.hpp"
#include "Catch2/extras/catch_amalgamated.hpp"

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};


TEST_CASE("test List", "[List]") {
    SECTION("test Empty") {
        List list;
        CHECK(list.Empty() == 1);
    };
    SECTION("test Size") {
        List list;
        list.PushFront(1);
        list.PushFront(2);
        CHECK(list.Size() == 2);
    }
    SECTION("test Clear") {
        List list;
        list.PushFront(1);
        list.PushFront(2);
        list.Clear();
        CHECK(list.Empty() == 1);
        CHECK(list.Size() == 0);
    }
    SECTION("test PushBack") {
        List list;
        list.PushBack(1);
        list.PushBack(5);
        CHECK(list.PopBack() == 5);
    }
    SECTION("test PushFront") {
        List list;
        list.PushFront(1);
        list.PushFront(5);
        CHECK(list.PopFront() == 5);
    }
    SECTION("test PopBack") {
        List list;
        CHECK_THROWS_WITH(list.PopBack(), "list is empty");
    }
    SECTION("test PopFront") {
        List list;
        CHECK_THROWS_WITH(list.PopFront(), "list is empty");
    }
    SECTION("test general") {
        List list;
        CHECK(list.Empty() == 1);
        list.PushBack(1);
        CHECK(list.Empty() == 0);
        list.PushBack(2);
        CHECK(list.PopBack() == 2);
        CHECK(list.PopFront() == 1);
        list.PushFront(3);
        list.PushFront(4);
        list.PushBack(12);
        CHECK(list.PopBack() == 12);
        CHECK(list.PopFront() == 4);
        list.Clear();
        CHECK(list.Empty() == 1);
        CHECK_THROWS_WITH(list.PopFront(), "list is empty");
        CHECK_THROWS_WITH(list.PopBack(), "list is empty");
    }
};


int main()
{
    return Catch::Session().run();
}
