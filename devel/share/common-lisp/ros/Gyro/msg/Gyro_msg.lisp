; Auto-generated. Do not edit!


(cl:in-package Gyro-msg)


;//! \htmlinclude Gyro_msg.msg.html

(cl:defclass <Gyro_msg> (roslisp-msg-protocol:ros-message)
  ((data
    :reader data
    :initarg :data
    :type cl:integer
    :initform 0))
)

(cl:defclass Gyro_msg (<Gyro_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Gyro_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Gyro_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Gyro-msg:<Gyro_msg> is deprecated: use Gyro-msg:Gyro_msg instead.")))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <Gyro_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Gyro-msg:data-val is deprecated.  Use Gyro-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Gyro_msg>) ostream)
  "Serializes a message object of type '<Gyro_msg>"
  (cl:let* ((signed (cl:slot-value msg 'data)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Gyro_msg>) istream)
  "Deserializes a message object of type '<Gyro_msg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'data) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Gyro_msg>)))
  "Returns string type for a message object of type '<Gyro_msg>"
  "Gyro/Gyro_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Gyro_msg)))
  "Returns string type for a message object of type 'Gyro_msg"
  "Gyro/Gyro_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Gyro_msg>)))
  "Returns md5sum for a message object of type '<Gyro_msg>"
  "da5909fbe378aeaf85e547e830cc1bb7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Gyro_msg)))
  "Returns md5sum for a message object of type 'Gyro_msg"
  "da5909fbe378aeaf85e547e830cc1bb7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Gyro_msg>)))
  "Returns full string definition for message of type '<Gyro_msg>"
  (cl:format cl:nil "int32 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Gyro_msg)))
  "Returns full string definition for message of type 'Gyro_msg"
  (cl:format cl:nil "int32 data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Gyro_msg>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Gyro_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'Gyro_msg
    (cl:cons ':data (data msg))
))
