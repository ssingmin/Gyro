;; Auto-generated. Do not edit!


(when (boundp 'Gyro::Gyro_msg)
  (if (not (find-package "GYRO"))
    (make-package "GYRO"))
  (shadow 'Gyro_msg (find-package "GYRO")))
(unless (find-package "GYRO::GYRO_MSG")
  (make-package "GYRO::GYRO_MSG"))

(in-package "ROS")
;;//! \htmlinclude Gyro_msg.msg.html


(defclass Gyro::Gyro_msg
  :super ros::object
  :slots (_data ))

(defmethod Gyro::Gyro_msg
  (:init
   (&key
    ((:data __data) 0)
    )
   (send-super :init)
   (setq _data (round __data))
   self)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; int32 _data
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _data
       (write-long _data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _data
     (setq _data (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get Gyro::Gyro_msg :md5sum-) "da5909fbe378aeaf85e547e830cc1bb7")
(setf (get Gyro::Gyro_msg :datatype-) "Gyro/Gyro_msg")
(setf (get Gyro::Gyro_msg :definition-)
      "int32 data

")



(provide :Gyro/Gyro_msg "da5909fbe378aeaf85e547e830cc1bb7")


