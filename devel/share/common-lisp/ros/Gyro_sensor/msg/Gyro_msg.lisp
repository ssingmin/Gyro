; Auto-generated. Do not edit!


(cl:in-package Gyro_sensor-msg)


;//! \htmlinclude Gyro_msg.msg.html

(cl:defclass <Gyro_msg> (roslisp-msg-protocol:ros-message)
  ((a_x
    :reader a_x
    :initarg :a_x
    :type cl:float
    :initform 0.0)
   (a_y
    :reader a_y
    :initarg :a_y
    :type cl:float
    :initform 0.0)
   (a_z
    :reader a_z
    :initarg :a_z
    :type cl:float
    :initform 0.0)
   (w_x
    :reader w_x
    :initarg :w_x
    :type cl:float
    :initform 0.0)
   (w_y
    :reader w_y
    :initarg :w_y
    :type cl:float
    :initform 0.0)
   (w_z
    :reader w_z
    :initarg :w_z
    :type cl:float
    :initform 0.0)
   (an_x
    :reader an_x
    :initarg :an_x
    :type cl:float
    :initform 0.0)
   (an_y
    :reader an_y
    :initarg :an_y
    :type cl:float
    :initform 0.0)
   (an_z
    :reader an_z
    :initarg :an_z
    :type cl:float
    :initform 0.0))
)

(cl:defclass Gyro_msg (<Gyro_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Gyro_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Gyro_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Gyro_sensor-msg:<Gyro_msg> is deprecated: use Gyro_sensor-msg:Gyro_msg instead.")))

(cl:ensure-generic-function 'a_x-val :lambda-list '(m))
(cl:defmethod a_x-val ((m <Gyro_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Gyro_sensor-msg:a_x-val is deprecated.  Use Gyro_sensor-msg:a_x instead.")
  (a_x m))

(cl:ensure-generic-function 'a_y-val :lambda-list '(m))
(cl:defmethod a_y-val ((m <Gyro_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Gyro_sensor-msg:a_y-val is deprecated.  Use Gyro_sensor-msg:a_y instead.")
  (a_y m))

(cl:ensure-generic-function 'a_z-val :lambda-list '(m))
(cl:defmethod a_z-val ((m <Gyro_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Gyro_sensor-msg:a_z-val is deprecated.  Use Gyro_sensor-msg:a_z instead.")
  (a_z m))

(cl:ensure-generic-function 'w_x-val :lambda-list '(m))
(cl:defmethod w_x-val ((m <Gyro_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Gyro_sensor-msg:w_x-val is deprecated.  Use Gyro_sensor-msg:w_x instead.")
  (w_x m))

(cl:ensure-generic-function 'w_y-val :lambda-list '(m))
(cl:defmethod w_y-val ((m <Gyro_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Gyro_sensor-msg:w_y-val is deprecated.  Use Gyro_sensor-msg:w_y instead.")
  (w_y m))

(cl:ensure-generic-function 'w_z-val :lambda-list '(m))
(cl:defmethod w_z-val ((m <Gyro_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Gyro_sensor-msg:w_z-val is deprecated.  Use Gyro_sensor-msg:w_z instead.")
  (w_z m))

(cl:ensure-generic-function 'an_x-val :lambda-list '(m))
(cl:defmethod an_x-val ((m <Gyro_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Gyro_sensor-msg:an_x-val is deprecated.  Use Gyro_sensor-msg:an_x instead.")
  (an_x m))

(cl:ensure-generic-function 'an_y-val :lambda-list '(m))
(cl:defmethod an_y-val ((m <Gyro_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Gyro_sensor-msg:an_y-val is deprecated.  Use Gyro_sensor-msg:an_y instead.")
  (an_y m))

(cl:ensure-generic-function 'an_z-val :lambda-list '(m))
(cl:defmethod an_z-val ((m <Gyro_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Gyro_sensor-msg:an_z-val is deprecated.  Use Gyro_sensor-msg:an_z instead.")
  (an_z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Gyro_msg>) ostream)
  "Serializes a message object of type '<Gyro_msg>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'w_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'w_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'w_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'an_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'an_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'an_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Gyro_msg>) istream)
  "Deserializes a message object of type '<Gyro_msg>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a_z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'w_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'w_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'w_z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'an_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'an_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'an_z) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Gyro_msg>)))
  "Returns string type for a message object of type '<Gyro_msg>"
  "Gyro_sensor/Gyro_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Gyro_msg)))
  "Returns string type for a message object of type 'Gyro_msg"
  "Gyro_sensor/Gyro_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Gyro_msg>)))
  "Returns md5sum for a message object of type '<Gyro_msg>"
  "fb2bb114d1e350ea2deb434716fc40d9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Gyro_msg)))
  "Returns md5sum for a message object of type 'Gyro_msg"
  "fb2bb114d1e350ea2deb434716fc40d9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Gyro_msg>)))
  "Returns full string definition for message of type '<Gyro_msg>"
  (cl:format cl:nil "float32 a_x~%float32 a_y~%float32 a_z~%~%float32 w_x~%float32 w_y~%float32 w_z~%~%float32 an_x~%float32 an_y~%float32 an_z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Gyro_msg)))
  "Returns full string definition for message of type 'Gyro_msg"
  (cl:format cl:nil "float32 a_x~%float32 a_y~%float32 a_z~%~%float32 w_x~%float32 w_y~%float32 w_z~%~%float32 an_x~%float32 an_y~%float32 an_z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Gyro_msg>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Gyro_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'Gyro_msg
    (cl:cons ':a_x (a_x msg))
    (cl:cons ':a_y (a_y msg))
    (cl:cons ':a_z (a_z msg))
    (cl:cons ':w_x (w_x msg))
    (cl:cons ':w_y (w_y msg))
    (cl:cons ':w_z (w_z msg))
    (cl:cons ':an_x (an_x msg))
    (cl:cons ':an_y (an_y msg))
    (cl:cons ':an_z (an_z msg))
))
