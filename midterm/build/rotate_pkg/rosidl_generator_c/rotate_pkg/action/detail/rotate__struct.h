// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rotate_pkg:action/Rotate.idl
// generated code does not contain a copyright notice

#ifndef ROTATE_PKG__ACTION__DETAIL__ROTATE__STRUCT_H_
#define ROTATE_PKG__ACTION__DETAIL__ROTATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Rotate in the package rotate_pkg.
typedef struct rotate_pkg__action__Rotate_Goal
{
  double angle;
} rotate_pkg__action__Rotate_Goal;

// Struct for a sequence of rotate_pkg__action__Rotate_Goal.
typedef struct rotate_pkg__action__Rotate_Goal__Sequence
{
  rotate_pkg__action__Rotate_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotate_pkg__action__Rotate_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/Rotate in the package rotate_pkg.
typedef struct rotate_pkg__action__Rotate_Result
{
  bool success;
} rotate_pkg__action__Rotate_Result;

// Struct for a sequence of rotate_pkg__action__Rotate_Result.
typedef struct rotate_pkg__action__Rotate_Result__Sequence
{
  rotate_pkg__action__Rotate_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotate_pkg__action__Rotate_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Rotate in the package rotate_pkg.
typedef struct rotate_pkg__action__Rotate_Feedback
{
  double reamining_angle;
} rotate_pkg__action__Rotate_Feedback;

// Struct for a sequence of rotate_pkg__action__Rotate_Feedback.
typedef struct rotate_pkg__action__Rotate_Feedback__Sequence
{
  rotate_pkg__action__Rotate_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotate_pkg__action__Rotate_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "rotate_pkg/action/detail/rotate__struct.h"

/// Struct defined in action/Rotate in the package rotate_pkg.
typedef struct rotate_pkg__action__Rotate_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  rotate_pkg__action__Rotate_Goal goal;
} rotate_pkg__action__Rotate_SendGoal_Request;

// Struct for a sequence of rotate_pkg__action__Rotate_SendGoal_Request.
typedef struct rotate_pkg__action__Rotate_SendGoal_Request__Sequence
{
  rotate_pkg__action__Rotate_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotate_pkg__action__Rotate_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Rotate in the package rotate_pkg.
typedef struct rotate_pkg__action__Rotate_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} rotate_pkg__action__Rotate_SendGoal_Response;

// Struct for a sequence of rotate_pkg__action__Rotate_SendGoal_Response.
typedef struct rotate_pkg__action__Rotate_SendGoal_Response__Sequence
{
  rotate_pkg__action__Rotate_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotate_pkg__action__Rotate_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Rotate in the package rotate_pkg.
typedef struct rotate_pkg__action__Rotate_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} rotate_pkg__action__Rotate_GetResult_Request;

// Struct for a sequence of rotate_pkg__action__Rotate_GetResult_Request.
typedef struct rotate_pkg__action__Rotate_GetResult_Request__Sequence
{
  rotate_pkg__action__Rotate_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotate_pkg__action__Rotate_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "rotate_pkg/action/detail/rotate__struct.h"

/// Struct defined in action/Rotate in the package rotate_pkg.
typedef struct rotate_pkg__action__Rotate_GetResult_Response
{
  int8_t status;
  rotate_pkg__action__Rotate_Result result;
} rotate_pkg__action__Rotate_GetResult_Response;

// Struct for a sequence of rotate_pkg__action__Rotate_GetResult_Response.
typedef struct rotate_pkg__action__Rotate_GetResult_Response__Sequence
{
  rotate_pkg__action__Rotate_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotate_pkg__action__Rotate_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "rotate_pkg/action/detail/rotate__struct.h"

/// Struct defined in action/Rotate in the package rotate_pkg.
typedef struct rotate_pkg__action__Rotate_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  rotate_pkg__action__Rotate_Feedback feedback;
} rotate_pkg__action__Rotate_FeedbackMessage;

// Struct for a sequence of rotate_pkg__action__Rotate_FeedbackMessage.
typedef struct rotate_pkg__action__Rotate_FeedbackMessage__Sequence
{
  rotate_pkg__action__Rotate_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rotate_pkg__action__Rotate_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROTATE_PKG__ACTION__DETAIL__ROTATE__STRUCT_H_
