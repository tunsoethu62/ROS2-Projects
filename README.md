# ROS2 Robot Motion Package

A collection of ROS2 Python nodes for controlling robot motion, including circle driving, odometry logging, square path execution via services, and angle rotation via actions.

---

## Package Structure

```
.
├── circle_publisher.py       # Publishes constant velocity commands to drive in a circle
├── odom_logger.py            # Subscribes to odometry and logs position/orientation
├── square_service_server.py  # Service server that drives the robot in a square path
├── square_service_client.py  # Service client that triggers the square motion
├── rotate_action_server.py   # Action server that rotates the robot by a given angle
└── rotate_action_client.py   # Action client that sends a rotation goal
```

---

## Prerequisites

- ROS2 (Humble or later recommended)
- Python 3.8+
- `tf_transformations` package (for `odom_logger.py`)
- Custom action definition: `rotate_pkg/action/Rotate.action`

Install Python dependencies:

```bash
pip install transforms3d
sudo apt install ros-<distro>-tf-transformations
```

---

## Nodes

### 1. `circle_publisher.py` — Circle Publisher

Drives the robot in a continuous circle by publishing `Twist` messages at 10 Hz.

**Published Topics:**

| Topic | Type | Description |
|-------|------|-------------|
| `/cmd_vel` | `geometry_msgs/Twist` | Linear and angular velocity commands |

**Motion parameters:**

- Linear velocity: `0.22 m/s`
- Angular velocity: `0.44 rad/s`

**Run:**

```bash
ros2 run <package_name> circle_publisher
```

---

### 2. `odom_logger.py` — Odometry Logger

Subscribes to `/odom` and logs the robot's position (x, y) and yaw angle every second.

**Subscribed Topics:**

| Topic | Type | Description |
|-------|------|-------------|
| `/odom` | `nav_msgs/Odometry` | Odometry data from the robot |

**Run:**

```bash
ros2 run <package_name> odom_logger
```

**Sample output:**

```
[INFO] Position:
x: 0.42, y: 0.11

Orientation:
Yaw: 1.5708
```

---

### 3. `square_service_server.py` — Square Motion Service Server

Exposes a `move_square` service. When called, the robot drives in a square with 0.5 m sides.

**Services:**

| Service | Type | Description |
|---------|------|-------------|
| `move_square` | `std_srvs/Empty` | Triggers a square motion pattern |

**Published Topics:**

| Topic | Type | Description |
|-------|------|-------------|
| `/cmd_vel` | `geometry_msgs/Twist` | Velocity commands during motion |

**Motion parameters:**

- Linear speed: `0.2 m/s`
- Angular speed: `0.5 rad/s`
- Side length: `0.5 m`

**Run:**

```bash
ros2 run <package_name> square_service_server
```

---

### 4. `square_service_client.py` — Square Motion Service Client

Calls the `move_square` service once and shuts down after receiving a response.

**Run:**

```bash
ros2 run <package_name> square_service_client
```

> Make sure `square_service_server` is running before starting the client.

---

### 5. `rotate_action_server.py` — Rotate Action Server

Action server that rotates the robot by a specified angle (in radians) using closed-loop yaw control via odometry feedback.

**Actions:**

| Action | Type | Description |
|--------|------|-------------|
| `rotate` | `rotate_pkg/Rotate` | Rotates by a given angle with feedback |

**Subscribed Topics:**

| Topic | Type | Description |
|-------|------|-------------|
| `/odom` | `nav_msgs/Odometry` | Used for real-time yaw estimation |

**Published Topics:**

| Topic | Type | Description |
|-------|------|-------------|
| `/cmd_vel` | `geometry_msgs/Twist` | Angular velocity commands |

**Control parameters:**

- Proportional gain (`kp`): `1.0`
- Tolerance: `10 degrees (0.175 rad)`
- Max angular velocity: `±1.5 rad/s`

Uses `MultiThreadedExecutor` and `ReentrantCallbackGroup` to handle concurrent odometry and action callbacks.

**Run:**

```bash
ros2 run <package_name> rotate_action_server
```

---

### 6. `rotate_action_client.py` — Rotate Action Client

Sends a rotation goal to the action server, monitors feedback, and logs the result.

**Default goal:** `3.14 radians (~180°)`

**Run:**

```bash
ros2 run <package_name> rotate_action_client
```

> Make sure `rotate_action_server` is running before starting the client.

---

## Custom Action Definition

The `rotate_action_server` and `rotate_action_client` rely on a custom action type. Create the following file in your package:

**`rotate_pkg/action/Rotate.action`**

```
# Goal
float64 angle
---
# Result
bool success
---
# Feedback
float64 reamining_angle
```

> Note: `reamining_angle` is spelled as-is in the source code — keep consistent to avoid runtime errors.

---

## Quick Start

### Drive in a circle

```bash
ros2 run <package_name> circle_publisher
```

### Log odometry

```bash
ros2 run <package_name> odom_logger
```

### Drive in a square (service)

```bash
# Terminal 1
ros2 run <package_name> square_service_server

# Terminal 2
ros2 run <package_name> square_service_client
```

### Rotate by an angle (action)

```bash
# Terminal 1
ros2 run <package_name> rotate_action_server

# Terminal 2
ros2 run <package_name> rotate_action_client
```

---

## Notes

- All velocity commands are published to `/cmd_vel`. Ensure your robot or simulator (e.g., Gazebo, TurtleBot3) is subscribed to this topic.
- The `square_service_server` uses `time.sleep()` for timing, which blocks the executor. For production use, consider a timer-based or async approach.
- The `rotate_action_server` normalizes yaw errors using `atan2` to handle angle wraparound correctly.
