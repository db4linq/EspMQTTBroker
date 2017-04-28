#ifndef _MQTT_SERVER_H_
#define _MQTT_SERVER_H_

#include "c_types.h"
#include "osapi.h"
#include "os_type.h"
#include "lwip/ip.h"
#include "lwip/app/espconn.h"
#include "lwip/app/espconn_tcp.h"

#include "mqtt.h"

typedef struct _MQTT_ClientCon {
  struct espconn *pCon;
//  uint8_t security;
//  uint32_t port;
//  ip_addr_t ip;
  mqtt_state_t  mqtt_state;
  mqtt_connect_info_t connect_info;
//  MqttCallback connectedCb;
//  MqttCallback disconnectedCb;
//  MqttCallback publishedCb;
//  MqttCallback timeoutCb;
//  MqttDataCallback dataCb;
  ETSTimer mqttTimer;
  uint32_t sendTimeout;
  tConnState connState;
  QUEUE msgQueue;
  void* user_data;
  struct _MQTT_ClientCon *next;
} MQTT_ClientCon;

extern MQTT_ClientCon *clientcon_list;

bool MQTT_server_start(uint16_t portno, uint16_t max_subscriptions, uint16_t max_retained_topics);

#endif /* _MQTT_SERVER_H_ */
