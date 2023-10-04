#pragma once

#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <string>
#include <cstdint>
#include <set>

#include "../date/date.h"

using namespace std;

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    Or,
    And
};

struct Node {
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
    virtual ~Node() = default;
};

struct EmptyNode : public Node {
    EmptyNode() {}

    bool Evaluate(const Date& date, const string& event) const override {
        return true;
    }
};

struct DateComparisonNode : public Node {
    DateComparisonNode(const Comparison& cmp, const Date& date) : _cmp(cmp), _date(date) {

    }

    bool Evaluate(const Date& date, const string& event) const override;

private:
    const Comparison _cmp;
    const Date _date;
};

struct EventComparisonNode : public Node {
    EventComparisonNode(const Comparison& cmp, const string& event) : _cmp(cmp), _event(event) {}

    bool Evaluate(const Date& date, const string& event) const override;

private:
    const Comparison _cmp;
    const string _event;
};

struct LogicalOperationNode : public Node {
    LogicalOperationNode(
        const LogicalOperation& lo,
        shared_ptr<Node> left,
        shared_ptr<Node> right
    ) : _lo(lo), _left(left), _right(right) {}

    bool Evaluate(const Date& date, const string& event) const override;

private:
    const LogicalOperation _lo;
    const shared_ptr<const Node> _left, _right;
};