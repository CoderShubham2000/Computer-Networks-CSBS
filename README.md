# Computer-Networks-CSBS
CN Assignment c program files for CSBS, Sister Nivedita University Students

1. TCP Single-Client <br><strong>Commands to Execute:</strong><br><i>In Terminal 1:</i> -> gcc tcp_single_server.c -o server<br><i>In Terminal 2:</i> -> gcc tcp_single_client.c -o client<br><i>Then in Terminal 1:</i><br>./server<br><i>Then in Terminal 2:</i><br> ./client
2. TCP Multi-Client <br><strong>Commands to Execute:</strong><br><i>In Terminal 1:</i> -> gcc tcp_multi_server.c -o server -lpthread<br><i>In Terminal 2:</i> -> gcc tcp_multi_client.c -o client -lpthread<br><i>Then in Terminal 1:</i><br>./server<br><i>Then in Terminal 2:</i><br> ./client
3. UDP Multi-Client <br><strong>Commands to Execute:</strong><br><i>In Terminal 1:</i> -> gcc udp_multicasting_receiver.c -o receiver<br><i>In Terminal 2:</i> -> gcc udp_multicasting_receiver.c -o receiver<br><i>In Terminal 3:</i> -> gcc udp_multicasting_sender.c -o sender<br><i>Then in Terminal 1:</i><br>./receiver<br><i>Then in Terminal 2:</i><br> ./receiver<i><br>Then in Terminal 3:</i><br>./sender
4. Chat Server using UDP <br><strong>Commands to Execute:</strong><br><i>In Terminal 1:</i> -> gcc chat_udp_server1.c -o s1 -lpthread<br><i>In Terminal 2:</i> -> gcc chat_udp_server2.c -o s2 -lpthread<br><i>Then in Terminal 1:</i><br>./s1<br><i>Then in Terminal 2:</i><br> ./s2<br>Enter any message in Terminal 1 and Reply from Terminal 2
5. Multicasting <br>
6. Implement the following group structure using multicasting <br><strong>Commands to Execute:</strong><br><i>In Terminal 1:</i> -> gcc multicast_group_A.c -o A -lpthread<br><i>In Terminal 2:</i> -> gcc multicast_group_B.c -o B -lpthread<br><i>In Terminal 3:</i> -> gcc multicast_group_C.c -o C -lpthread<br><i>In Terminal 4:</i> -> gcc multicast_group_D.c -o D -lpthread<br><i>Then in Terminal 1:</i><br>./A<br><i>Then in Terminal 2:</i><br> ./B<i><br>Then in Terminal 3:</i><br>./C<br>Then in Terminal 4:</i><br>./D<br>Type in 3 for Terminal 1 and then Type in Y/y and press enter, then go to Terminal 3 and see that it has received nothing.

Refer to Table from this link for Qn 6: https://docs.google.com/document/d/1XZ7rJqnNk9dULUl0hgYniQy0Ahr3UdChrk67vqu_Rqs/edit
