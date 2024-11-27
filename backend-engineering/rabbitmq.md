# RabbitMQ

## What is RabbitMQ?
  - Message Queue
    - A producer-consumer architecture for message passing between services.
    - Benefits of using a message queue
      - Decoupling of services
      - Scalability of services
      - Increased performance by taking out the message queue implementation to a different machine
    - RabbitMQ: A message broker that implements the AMQP (Advanced Message Queuing Protocol)
      - The producer service sends messages to the exchange.
      - The exchange is connected to multiple queues. Each queue is connected by bindings, which are identifiable by binding keys.
      - The consumer services subscribe to the queues.

## Exchange
- Types of exchanges
  - Fan-out exchange: Each message will be passed onto every connected queue.
  - Direct exchange: Each message will have a routing key. The message will be sent to a queue with a binding key that matches the routing key.
  - Topic exchange: Direct exchange, but the routing key is matched by pattern with the binding key.
  - Header exchange: The routing key is ignored, the message is passed on only according to the header.
  - Default exchange: The routing key contains the name of the queue, the message is passed to the queue that has the name of the routing key.
