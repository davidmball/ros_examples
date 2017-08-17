ROS Examples
============

A collection of examples for the Online ROS site where everyone can view, edit, compile and run ROS code.

See instructions here: https://github.com/davidmball/online_ros

### Contributions

Pull requests with new examples are very welcome. Please keep the example focussed on one particular aspect of ROS.

Please follow the ROS style guide (http://wiki.ros.org/CppStyleGuide)
with the following exceptions:
* Exceptions are allowed.
* C++11/14 is allowed and encouraged. 

The xml file has the following elements
<example>Surround the entire sml will this tag.</exmaple>
<title>This title will be displayed in the index list, top of the example page, and in the google search result.</titl>
<run_cmd>This is the cmd that will be run in the docker container after compilation</run_cmd>
<description> This description will be displayed in the index list, at the top of the example page, and suggested to google for the snippet in its search results</description>
<ros_version>Which ROS build does this support. At the moment there is only a kinetic container. ROS2 support is planned</ros_version>
<time_limit>This is the amount of time that compilation and execution of the example will last</time_limit>
<start_file>This is the file that is shown by default to the end user on page load</start_file>
<tag>A number of tags that describe this example. These are shown on the index page listing.</tag>
<feedback>Two parent feeback sections must be included. These configure the interactive parts for the user</feeback>
<tab>Which of the tabs should be displayed in teh feedback panel by default. At the moment can be "topics", "nodes", "params", "service", "viz"</tab>
<topic>(optional) Some tabs require the topic to work with. Eg the "topics" needs to know the default topic.</topic>
<msg_type>Describe the msg type for the topic. Hopefully in the future. this can be depricated and gotten from the server.</msg_type>

### License

The code is released under the BSD license.
Except where otherwise noted, the web pages and documentation are licensed under Creative Commons Attribution 3.0. 





