1. Reduse the use of data-member directly,because in case this data-member requires modification or change , it does not affect
    rest of the class,but use setters/getters to get it .
1. Whoever creates a pointer is responsible for destructing it.
1. return Refrance breaks Data-Hiding concept. User has access to private data and can corrupt the system 
    be careful with it