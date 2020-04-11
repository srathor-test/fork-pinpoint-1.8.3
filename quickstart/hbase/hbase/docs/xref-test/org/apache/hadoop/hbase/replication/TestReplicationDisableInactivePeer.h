<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8" />
<title>TestReplicationDisableInactivePeer xref</title>
<link type="text/css" rel="stylesheet" href="../../../../../stylesheet.css" />
</head>
<body>
<div id="overview"><a href="../../../../../../testapidocs/org/apache/hadoop/hbase/replication/TestReplicationDisableInactivePeer.html">View Javadoc</a></div><pre>

<a class="jxr_linenumber" name="1" href="#1">1</a>   <em class="jxr_comment">/*</em>
<a class="jxr_linenumber" name="2" href="#2">2</a>   <em class="jxr_comment"> *</em>
<a class="jxr_linenumber" name="3" href="#3">3</a>   <em class="jxr_comment"> * Licensed to the Apache Software Foundation (ASF) under one</em>
<a class="jxr_linenumber" name="4" href="#4">4</a>   <em class="jxr_comment"> * or more contributor license agreements.  See the NOTICE file</em>
<a class="jxr_linenumber" name="5" href="#5">5</a>   <em class="jxr_comment"> * distributed with this work for additional information</em>
<a class="jxr_linenumber" name="6" href="#6">6</a>   <em class="jxr_comment"> * regarding copyright ownership.  The ASF licenses this file</em>
<a class="jxr_linenumber" name="7" href="#7">7</a>   <em class="jxr_comment"> * to you under the Apache License, Version 2.0 (the</em>
<a class="jxr_linenumber" name="8" href="#8">8</a>   <em class="jxr_comment"> * "License"); you may not use this file except in compliance</em>
<a class="jxr_linenumber" name="9" href="#9">9</a>   <em class="jxr_comment"> * with the License.  You may obtain a copy of the License at</em>
<a class="jxr_linenumber" name="10" href="#10">10</a>  <em class="jxr_comment"> *</em>
<a class="jxr_linenumber" name="11" href="#11">11</a>  <em class="jxr_comment"> *     <a href="http://www.apache.org/licenses/LICENSE-2.0" target="alexandria_uri">http://www.apache.org/licenses/LICENSE-2.0</a></em>
<a class="jxr_linenumber" name="12" href="#12">12</a>  <em class="jxr_comment"> *</em>
<a class="jxr_linenumber" name="13" href="#13">13</a>  <em class="jxr_comment"> * Unless required by applicable law or agreed to in writing, software</em>
<a class="jxr_linenumber" name="14" href="#14">14</a>  <em class="jxr_comment"> * distributed under the License is distributed on an "AS IS" BASIS,</em>
<a class="jxr_linenumber" name="15" href="#15">15</a>  <em class="jxr_comment"> * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.</em>
<a class="jxr_linenumber" name="16" href="#16">16</a>  <em class="jxr_comment"> * See the License for the specific language governing permissions and</em>
<a class="jxr_linenumber" name="17" href="#17">17</a>  <em class="jxr_comment"> * limitations under the License.</em>
<a class="jxr_linenumber" name="18" href="#18">18</a>  <em class="jxr_comment"> */</em>
<a class="jxr_linenumber" name="19" href="#19">19</a>  <strong class="jxr_keyword">package</strong> org.apache.hadoop.hbase.replication;
<a class="jxr_linenumber" name="20" href="#20">20</a>  
<a class="jxr_linenumber" name="21" href="#21">21</a>  <strong class="jxr_keyword">import</strong> org.apache.commons.logging.Log;
<a class="jxr_linenumber" name="22" href="#22">22</a>  <strong class="jxr_keyword">import</strong> org.apache.commons.logging.LogFactory;
<a class="jxr_linenumber" name="23" href="#23">23</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.testclassification.LargeTests;
<a class="jxr_linenumber" name="24" href="#24">24</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.client.Get;
<a class="jxr_linenumber" name="25" href="#25">25</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.client.Put;
<a class="jxr_linenumber" name="26" href="#26">26</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.client.Result;
<a class="jxr_linenumber" name="27" href="#27">27</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.util.Bytes;
<a class="jxr_linenumber" name="28" href="#28">28</a>  <strong class="jxr_keyword">import</strong> org.junit.Test;
<a class="jxr_linenumber" name="29" href="#29">29</a>  <strong class="jxr_keyword">import</strong> org.junit.experimental.categories.Category;
<a class="jxr_linenumber" name="30" href="#30">30</a>  
<a class="jxr_linenumber" name="31" href="#31">31</a>  <strong class="jxr_keyword">import</strong> <strong class="jxr_keyword">static</strong> org.junit.Assert.assertArrayEquals;
<a class="jxr_linenumber" name="32" href="#32">32</a>  <strong class="jxr_keyword">import</strong> <strong class="jxr_keyword">static</strong> org.junit.Assert.fail;
<a class="jxr_linenumber" name="33" href="#33">33</a>  
<a class="jxr_linenumber" name="34" href="#34">34</a>  @Category(LargeTests.<strong class="jxr_keyword">class</strong>)
<a class="jxr_linenumber" name="35" href="#35">35</a>  <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">class</strong> <a href="../../../../../org/apache/hadoop/hbase/replication/TestReplicationDisableInactivePeer.html">TestReplicationDisableInactivePeer</a> <strong class="jxr_keyword">extends</strong> <a href="../../../../../org/apache/hadoop/hbase/replication/TestReplicationBase.html">TestReplicationBase</a> {
<a class="jxr_linenumber" name="36" href="#36">36</a>  
<a class="jxr_linenumber" name="37" href="#37">37</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">final</strong> Log LOG = LogFactory.getLog(TestReplicationDisableInactivePeer.<strong class="jxr_keyword">class</strong>);
<a class="jxr_linenumber" name="38" href="#38">38</a>  
<a class="jxr_linenumber" name="39" href="#39">39</a>    <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="40" href="#40">40</a>  <em class="jxr_javadoccomment">   * Test disabling an inactive peer. Add a peer which is inactive, trying to</em>
<a class="jxr_linenumber" name="41" href="#41">41</a>  <em class="jxr_javadoccomment">   * insert, disable the peer, then activate the peer and make sure nothing is</em>
<a class="jxr_linenumber" name="42" href="#42">42</a>  <em class="jxr_javadoccomment">   * replicated. In Addition, enable the peer and check the updates are</em>
<a class="jxr_linenumber" name="43" href="#43">43</a>  <em class="jxr_javadoccomment">   * replicated.</em>
<a class="jxr_linenumber" name="44" href="#44">44</a>  <em class="jxr_javadoccomment">   *</em>
<a class="jxr_linenumber" name="45" href="#45">45</a>  <em class="jxr_javadoccomment">   * @throws Exception</em>
<a class="jxr_linenumber" name="46" href="#46">46</a>  <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="47" href="#47">47</a>    @Test(timeout = 600000)
<a class="jxr_linenumber" name="48" href="#48">48</a>    <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> testDisableInactivePeer() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="49" href="#49">49</a>  
<a class="jxr_linenumber" name="50" href="#50">50</a>      <em class="jxr_comment">// enabling and shutdown the peer</em>
<a class="jxr_linenumber" name="51" href="#51">51</a>      admin.enablePeer(<span class="jxr_string">"2"</span>);
<a class="jxr_linenumber" name="52" href="#52">52</a>      utility2.shutdownMiniHBaseCluster();
<a class="jxr_linenumber" name="53" href="#53">53</a>  
<a class="jxr_linenumber" name="54" href="#54">54</a>      byte[] rowkey = Bytes.toBytes(<span class="jxr_string">"disable inactive peer"</span>);
<a class="jxr_linenumber" name="55" href="#55">55</a>      Put put = <strong class="jxr_keyword">new</strong> Put(rowkey);
<a class="jxr_linenumber" name="56" href="#56">56</a>      put.add(famName, row, row);
<a class="jxr_linenumber" name="57" href="#57">57</a>      htable1.put(put);
<a class="jxr_linenumber" name="58" href="#58">58</a>  
<a class="jxr_linenumber" name="59" href="#59">59</a>      <em class="jxr_comment">// wait for the sleep interval of the master cluster to become long</em>
<a class="jxr_linenumber" name="60" href="#60">60</a>      Thread.sleep(SLEEP_TIME * NB_RETRIES);
<a class="jxr_linenumber" name="61" href="#61">61</a>  
<a class="jxr_linenumber" name="62" href="#62">62</a>      <em class="jxr_comment">// disable and start the peer</em>
<a class="jxr_linenumber" name="63" href="#63">63</a>      admin.disablePeer(<span class="jxr_string">"2"</span>);
<a class="jxr_linenumber" name="64" href="#64">64</a>      utility2.startMiniHBaseCluster(1, 2);
<a class="jxr_linenumber" name="65" href="#65">65</a>      Get get = <strong class="jxr_keyword">new</strong> Get(rowkey);
<a class="jxr_linenumber" name="66" href="#66">66</a>      <strong class="jxr_keyword">for</strong> (<strong class="jxr_keyword">int</strong> i = 0; i &lt; NB_RETRIES; i++) {
<a class="jxr_linenumber" name="67" href="#67">67</a>        Result res = htable2.get(get);
<a class="jxr_linenumber" name="68" href="#68">68</a>        <strong class="jxr_keyword">if</strong> (res.size() &gt;= 1) {
<a class="jxr_linenumber" name="69" href="#69">69</a>          fail(<span class="jxr_string">"Replication wasn't disabled"</span>);
<a class="jxr_linenumber" name="70" href="#70">70</a>        } <strong class="jxr_keyword">else</strong> {
<a class="jxr_linenumber" name="71" href="#71">71</a>          LOG.info(<span class="jxr_string">"Row not replicated, let's wait a bit more..."</span>);
<a class="jxr_linenumber" name="72" href="#72">72</a>          Thread.sleep(SLEEP_TIME);
<a class="jxr_linenumber" name="73" href="#73">73</a>        }
<a class="jxr_linenumber" name="74" href="#74">74</a>      }
<a class="jxr_linenumber" name="75" href="#75">75</a>  
<a class="jxr_linenumber" name="76" href="#76">76</a>      <em class="jxr_comment">// Test enable replication</em>
<a class="jxr_linenumber" name="77" href="#77">77</a>      admin.enablePeer(<span class="jxr_string">"2"</span>);
<a class="jxr_linenumber" name="78" href="#78">78</a>      <em class="jxr_comment">// wait since the sleep interval would be long</em>
<a class="jxr_linenumber" name="79" href="#79">79</a>      Thread.sleep(SLEEP_TIME * NB_RETRIES);
<a class="jxr_linenumber" name="80" href="#80">80</a>      <strong class="jxr_keyword">for</strong> (<strong class="jxr_keyword">int</strong> i = 0; i &lt; NB_RETRIES; i++) {
<a class="jxr_linenumber" name="81" href="#81">81</a>        Result res = htable2.get(get);
<a class="jxr_linenumber" name="82" href="#82">82</a>        <strong class="jxr_keyword">if</strong> (res.size() == 0) {
<a class="jxr_linenumber" name="83" href="#83">83</a>          LOG.info(<span class="jxr_string">"Row not available"</span>);
<a class="jxr_linenumber" name="84" href="#84">84</a>          Thread.sleep(SLEEP_TIME * NB_RETRIES);
<a class="jxr_linenumber" name="85" href="#85">85</a>        } <strong class="jxr_keyword">else</strong> {
<a class="jxr_linenumber" name="86" href="#86">86</a>          assertArrayEquals(res.value(), row);
<a class="jxr_linenumber" name="87" href="#87">87</a>          <strong class="jxr_keyword">return</strong>;
<a class="jxr_linenumber" name="88" href="#88">88</a>        }
<a class="jxr_linenumber" name="89" href="#89">89</a>      }
<a class="jxr_linenumber" name="90" href="#90">90</a>      fail(<span class="jxr_string">"Waited too much time for put replication"</span>);
<a class="jxr_linenumber" name="91" href="#91">91</a>    }
<a class="jxr_linenumber" name="92" href="#92">92</a>  }
</pre>
<hr/><div id="footer">This page was automatically generated by <a href="http://maven.apache.org/">Maven</a></div></body>
</html>

