
(cl:in-package :asdf)

(defsystem "Gyro-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Gyro_msg" :depends-on ("_package_Gyro_msg"))
    (:file "_package_Gyro_msg" :depends-on ("_package"))
  ))