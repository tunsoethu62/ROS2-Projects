// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rotate_pkg:action/Rotate.idl
// generated code does not contain a copyright notice

#ifndef ROTATE_PKG__ACTION__DETAIL__ROTATE__BUILDER_HPP_
#define ROTATE_PKG__ACTION__DETAIL__ROTATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rotate_pkg/action/detail/rotate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rotate_pkg
{

namespace action
{

namespace builder
{

class Init_Rotate_Goal_angle
{
public:
  Init_Rotate_Goal_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rotate_pkg::action::Rotate_Goal angle(::rotate_pkg::action::Rotate_Goal::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotate_pkg::action::Rotate_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotate_pkg::action::Rotate_Goal>()
{
  return rotate_pkg::action::builder::Init_Rotate_Goal_angle();
}

}  // namespace rotate_pkg


namespace rotate_pkg
{

namespace action
{

namespace builder
{

class Init_Rotate_Result_success
{
public:
  Init_Rotate_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rotate_pkg::action::Rotate_Result success(::rotate_pkg::action::Rotate_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotate_pkg::action::Rotate_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotate_pkg::action::Rotate_Result>()
{
  return rotate_pkg::action::builder::Init_Rotate_Result_success();
}

}  // namespace rotate_pkg


namespace rotate_pkg
{

namespace action
{

namespace builder
{

class Init_Rotate_Feedback_reamining_angle
{
public:
  Init_Rotate_Feedback_reamining_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rotate_pkg::action::Rotate_Feedback reamining_angle(::rotate_pkg::action::Rotate_Feedback::_reamining_angle_type arg)
  {
    msg_.reamining_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotate_pkg::action::Rotate_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotate_pkg::action::Rotate_Feedback>()
{
  return rotate_pkg::action::builder::Init_Rotate_Feedback_reamining_angle();
}

}  // namespace rotate_pkg


namespace rotate_pkg
{

namespace action
{

namespace builder
{

class Init_Rotate_SendGoal_Request_goal
{
public:
  explicit Init_Rotate_SendGoal_Request_goal(::rotate_pkg::action::Rotate_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::rotate_pkg::action::Rotate_SendGoal_Request goal(::rotate_pkg::action::Rotate_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotate_pkg::action::Rotate_SendGoal_Request msg_;
};

class Init_Rotate_SendGoal_Request_goal_id
{
public:
  Init_Rotate_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Rotate_SendGoal_Request_goal goal_id(::rotate_pkg::action::Rotate_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Rotate_SendGoal_Request_goal(msg_);
  }

private:
  ::rotate_pkg::action::Rotate_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotate_pkg::action::Rotate_SendGoal_Request>()
{
  return rotate_pkg::action::builder::Init_Rotate_SendGoal_Request_goal_id();
}

}  // namespace rotate_pkg


namespace rotate_pkg
{

namespace action
{

namespace builder
{

class Init_Rotate_SendGoal_Response_stamp
{
public:
  explicit Init_Rotate_SendGoal_Response_stamp(::rotate_pkg::action::Rotate_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::rotate_pkg::action::Rotate_SendGoal_Response stamp(::rotate_pkg::action::Rotate_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotate_pkg::action::Rotate_SendGoal_Response msg_;
};

class Init_Rotate_SendGoal_Response_accepted
{
public:
  Init_Rotate_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Rotate_SendGoal_Response_stamp accepted(::rotate_pkg::action::Rotate_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Rotate_SendGoal_Response_stamp(msg_);
  }

private:
  ::rotate_pkg::action::Rotate_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotate_pkg::action::Rotate_SendGoal_Response>()
{
  return rotate_pkg::action::builder::Init_Rotate_SendGoal_Response_accepted();
}

}  // namespace rotate_pkg


namespace rotate_pkg
{

namespace action
{

namespace builder
{

class Init_Rotate_GetResult_Request_goal_id
{
public:
  Init_Rotate_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rotate_pkg::action::Rotate_GetResult_Request goal_id(::rotate_pkg::action::Rotate_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotate_pkg::action::Rotate_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotate_pkg::action::Rotate_GetResult_Request>()
{
  return rotate_pkg::action::builder::Init_Rotate_GetResult_Request_goal_id();
}

}  // namespace rotate_pkg


namespace rotate_pkg
{

namespace action
{

namespace builder
{

class Init_Rotate_GetResult_Response_result
{
public:
  explicit Init_Rotate_GetResult_Response_result(::rotate_pkg::action::Rotate_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::rotate_pkg::action::Rotate_GetResult_Response result(::rotate_pkg::action::Rotate_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotate_pkg::action::Rotate_GetResult_Response msg_;
};

class Init_Rotate_GetResult_Response_status
{
public:
  Init_Rotate_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Rotate_GetResult_Response_result status(::rotate_pkg::action::Rotate_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Rotate_GetResult_Response_result(msg_);
  }

private:
  ::rotate_pkg::action::Rotate_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotate_pkg::action::Rotate_GetResult_Response>()
{
  return rotate_pkg::action::builder::Init_Rotate_GetResult_Response_status();
}

}  // namespace rotate_pkg


namespace rotate_pkg
{

namespace action
{

namespace builder
{

class Init_Rotate_FeedbackMessage_feedback
{
public:
  explicit Init_Rotate_FeedbackMessage_feedback(::rotate_pkg::action::Rotate_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::rotate_pkg::action::Rotate_FeedbackMessage feedback(::rotate_pkg::action::Rotate_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rotate_pkg::action::Rotate_FeedbackMessage msg_;
};

class Init_Rotate_FeedbackMessage_goal_id
{
public:
  Init_Rotate_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Rotate_FeedbackMessage_feedback goal_id(::rotate_pkg::action::Rotate_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Rotate_FeedbackMessage_feedback(msg_);
  }

private:
  ::rotate_pkg::action::Rotate_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rotate_pkg::action::Rotate_FeedbackMessage>()
{
  return rotate_pkg::action::builder::Init_Rotate_FeedbackMessage_goal_id();
}

}  // namespace rotate_pkg

#endif  // ROTATE_PKG__ACTION__DETAIL__ROTATE__BUILDER_HPP_
