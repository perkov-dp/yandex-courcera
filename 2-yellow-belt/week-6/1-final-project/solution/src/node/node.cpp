#include "node.h"

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    switch(_cmp) {
        case Comparison::Less:
            return date < _date;
        case Comparison::LessOrEqual:
            return date <= _date;
        case Comparison::Greater:
            return date > _date;
        case Comparison::GreaterOrEqual:
            return date >= _date;
        case Comparison::Equal:
            return date == _date;
        case Comparison::NotEqual:
            return date != _date;
        default:
            break;
    }

    return false;
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    switch(_cmp) {
        case Comparison::Less:
            return event < _event;
        case Comparison::LessOrEqual:
            return event <= _event;
        case Comparison::Greater:
            return event > _event;
        case Comparison::GreaterOrEqual:
            return event >= _event;
        case Comparison::Equal:
            return event == _event;
        case Comparison::NotEqual:
            return event != _event;
        default:
            break;
    }

    return false;
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    switch(_lo) {
        case LogicalOperation::Or:
            return _left->Evaluate(date, event) || _right->Evaluate(date, event);
        case LogicalOperation::And:
            return _left->Evaluate(date, event) && _right->Evaluate(date, event);
        default:
            break;
    }

    return false;
}