;; Auto-generated. Do not edit!


(when (boundp 'Gyro_sensor::Gyro_msg)
  (if (not (find-package "GYRO_SENSOR"))
    (make-package "GYRO_SENSOR"))
  (shadow 'Gyro_msg (find-package "GYRO_SENSOR")))
(unless (find-package "GYRO_SENSOR::GYRO_MSG")
  (make-package "GYRO_SENSOR::GYRO_MSG"))

(in-package "ROS")
;;//! \htmlinclude Gyro_msg.msg.html


(defclass Gyro_sensor::Gyro_msg
  :super ros::object
  :slots (_a_x _a_y _a_z _w_x _w_y _w_z _an_x _an_y _an_z ))

(defmethod Gyro_sensor::Gyro_msg
  (:init
   (&key
    ((:a_x __a_x) 0.0)
    ((:a_y __a_y) 0.0)
    ((:a_z __a_z) 0.0)
    ((:w_x __w_x) 0.0)
    ((:w_y __w_y) 0.0)
    ((:w_z __w_z) 0.0)
    ((:an_x __an_x) 0.0)
    ((:an_y __an_y) 0.0)
    ((:an_z __an_z) 0.0)
    )
   (send-super :init)
   (setq _a_x (float __a_x))
   (setq _a_y (float __a_y))
   (setq _a_z (float __a_z))
   (setq _w_x (float __w_x))
   (setq _w_y (float __w_y))
   (setq _w_z (float __w_z))
   (setq _an_x (float __an_x))
   (setq _an_y (float __an_y))
   (setq _an_z (float __an_z))
   self)
  (:a_x
   (&optional __a_x)
   (if __a_x (setq _a_x __a_x)) _a_x)
  (:a_y
   (&optional __a_y)
   (if __a_y (setq _a_y __a_y)) _a_y)
  (:a_z
   (&optional __a_z)
   (if __a_z (setq _a_z __a_z)) _a_z)
  (:w_x
   (&optional __w_x)
   (if __w_x (setq _w_x __w_x)) _w_x)
  (:w_y
   (&optional __w_y)
   (if __w_y (setq _w_y __w_y)) _w_y)
  (:w_z
   (&optional __w_z)
   (if __w_z (setq _w_z __w_z)) _w_z)
  (:an_x
   (&optional __an_x)
   (if __an_x (setq _an_x __an_x)) _an_x)
  (:an_y
   (&optional __an_y)
   (if __an_y (setq _an_y __an_y)) _an_y)
  (:an_z
   (&optional __an_z)
   (if __an_z (setq _an_z __an_z)) _an_z)
  (:serialization-length
   ()
   (+
    ;; float32 _a_x
    4
    ;; float32 _a_y
    4
    ;; float32 _a_z
    4
    ;; float32 _w_x
    4
    ;; float32 _w_y
    4
    ;; float32 _w_z
    4
    ;; float32 _an_x
    4
    ;; float32 _an_y
    4
    ;; float32 _an_z
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _a_x
       (sys::poke _a_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a_y
       (sys::poke _a_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a_z
       (sys::poke _a_z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _w_x
       (sys::poke _w_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _w_y
       (sys::poke _w_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _w_z
       (sys::poke _w_z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _an_x
       (sys::poke _an_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _an_y
       (sys::poke _an_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _an_z
       (sys::poke _an_z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _a_x
     (setq _a_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a_y
     (setq _a_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a_z
     (setq _a_z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _w_x
     (setq _w_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _w_y
     (setq _w_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _w_z
     (setq _w_z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _an_x
     (setq _an_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _an_y
     (setq _an_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _an_z
     (setq _an_z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get Gyro_sensor::Gyro_msg :md5sum-) "fb2bb114d1e350ea2deb434716fc40d9")
(setf (get Gyro_sensor::Gyro_msg :datatype-) "Gyro_sensor/Gyro_msg")
(setf (get Gyro_sensor::Gyro_msg :definition-)
      "float32 a_x
float32 a_y
float32 a_z

float32 w_x
float32 w_y
float32 w_z

float32 an_x
float32 an_y
float32 an_z

")



(provide :Gyro_sensor/Gyro_msg "fb2bb114d1e350ea2deb434716fc40d9")


