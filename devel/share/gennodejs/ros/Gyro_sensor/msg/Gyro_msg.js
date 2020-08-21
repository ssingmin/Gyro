// Auto-generated. Do not edit!

// (in-package Gyro_sensor.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Gyro_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.a_x = null;
      this.a_y = null;
      this.a_z = null;
      this.w_x = null;
      this.w_y = null;
      this.w_z = null;
      this.an_x = null;
      this.an_y = null;
      this.an_z = null;
    }
    else {
      if (initObj.hasOwnProperty('a_x')) {
        this.a_x = initObj.a_x
      }
      else {
        this.a_x = 0.0;
      }
      if (initObj.hasOwnProperty('a_y')) {
        this.a_y = initObj.a_y
      }
      else {
        this.a_y = 0.0;
      }
      if (initObj.hasOwnProperty('a_z')) {
        this.a_z = initObj.a_z
      }
      else {
        this.a_z = 0.0;
      }
      if (initObj.hasOwnProperty('w_x')) {
        this.w_x = initObj.w_x
      }
      else {
        this.w_x = 0.0;
      }
      if (initObj.hasOwnProperty('w_y')) {
        this.w_y = initObj.w_y
      }
      else {
        this.w_y = 0.0;
      }
      if (initObj.hasOwnProperty('w_z')) {
        this.w_z = initObj.w_z
      }
      else {
        this.w_z = 0.0;
      }
      if (initObj.hasOwnProperty('an_x')) {
        this.an_x = initObj.an_x
      }
      else {
        this.an_x = 0.0;
      }
      if (initObj.hasOwnProperty('an_y')) {
        this.an_y = initObj.an_y
      }
      else {
        this.an_y = 0.0;
      }
      if (initObj.hasOwnProperty('an_z')) {
        this.an_z = initObj.an_z
      }
      else {
        this.an_z = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Gyro_msg
    // Serialize message field [a_x]
    bufferOffset = _serializer.float32(obj.a_x, buffer, bufferOffset);
    // Serialize message field [a_y]
    bufferOffset = _serializer.float32(obj.a_y, buffer, bufferOffset);
    // Serialize message field [a_z]
    bufferOffset = _serializer.float32(obj.a_z, buffer, bufferOffset);
    // Serialize message field [w_x]
    bufferOffset = _serializer.float32(obj.w_x, buffer, bufferOffset);
    // Serialize message field [w_y]
    bufferOffset = _serializer.float32(obj.w_y, buffer, bufferOffset);
    // Serialize message field [w_z]
    bufferOffset = _serializer.float32(obj.w_z, buffer, bufferOffset);
    // Serialize message field [an_x]
    bufferOffset = _serializer.float32(obj.an_x, buffer, bufferOffset);
    // Serialize message field [an_y]
    bufferOffset = _serializer.float32(obj.an_y, buffer, bufferOffset);
    // Serialize message field [an_z]
    bufferOffset = _serializer.float32(obj.an_z, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Gyro_msg
    let len;
    let data = new Gyro_msg(null);
    // Deserialize message field [a_x]
    data.a_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a_y]
    data.a_y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a_z]
    data.a_z = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [w_x]
    data.w_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [w_y]
    data.w_y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [w_z]
    data.w_z = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [an_x]
    data.an_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [an_y]
    data.an_y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [an_z]
    data.an_z = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 36;
  }

  static datatype() {
    // Returns string type for a message object
    return 'Gyro_sensor/Gyro_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fb2bb114d1e350ea2deb434716fc40d9';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 a_x
    float32 a_y
    float32 a_z
    
    float32 w_x
    float32 w_y
    float32 w_z
    
    float32 an_x
    float32 an_y
    float32 an_z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Gyro_msg(null);
    if (msg.a_x !== undefined) {
      resolved.a_x = msg.a_x;
    }
    else {
      resolved.a_x = 0.0
    }

    if (msg.a_y !== undefined) {
      resolved.a_y = msg.a_y;
    }
    else {
      resolved.a_y = 0.0
    }

    if (msg.a_z !== undefined) {
      resolved.a_z = msg.a_z;
    }
    else {
      resolved.a_z = 0.0
    }

    if (msg.w_x !== undefined) {
      resolved.w_x = msg.w_x;
    }
    else {
      resolved.w_x = 0.0
    }

    if (msg.w_y !== undefined) {
      resolved.w_y = msg.w_y;
    }
    else {
      resolved.w_y = 0.0
    }

    if (msg.w_z !== undefined) {
      resolved.w_z = msg.w_z;
    }
    else {
      resolved.w_z = 0.0
    }

    if (msg.an_x !== undefined) {
      resolved.an_x = msg.an_x;
    }
    else {
      resolved.an_x = 0.0
    }

    if (msg.an_y !== undefined) {
      resolved.an_y = msg.an_y;
    }
    else {
      resolved.an_y = 0.0
    }

    if (msg.an_z !== undefined) {
      resolved.an_z = msg.an_z;
    }
    else {
      resolved.an_z = 0.0
    }

    return resolved;
    }
};

module.exports = Gyro_msg;
