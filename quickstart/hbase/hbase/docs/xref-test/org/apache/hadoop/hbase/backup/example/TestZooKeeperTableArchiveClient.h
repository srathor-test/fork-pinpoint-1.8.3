<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8" />
<title>TestZooKeeperTableArchiveClient xref</title>
<link type="text/css" rel="stylesheet" href="../../../../../../stylesheet.css" />
</head>
<body>
<div id="overview"><a href="../../../../../../../testapidocs/org/apache/hadoop/hbase/backup/example/TestZooKeeperTableArchiveClient.html">View Javadoc</a></div><pre>

<a class="jxr_linenumber" name="1" href="#1">1</a>   <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="2" href="#2">2</a>   <em class="jxr_javadoccomment"> * Licensed to the Apache Software Foundation (ASF) under one</em>
<a class="jxr_linenumber" name="3" href="#3">3</a>   <em class="jxr_javadoccomment"> * or more contributor license agreements.  See the NOTICE file</em>
<a class="jxr_linenumber" name="4" href="#4">4</a>   <em class="jxr_javadoccomment"> * distributed with this work for additional information</em>
<a class="jxr_linenumber" name="5" href="#5">5</a>   <em class="jxr_javadoccomment"> * regarding copyright ownership.  The ASF licenses this file</em>
<a class="jxr_linenumber" name="6" href="#6">6</a>   <em class="jxr_javadoccomment"> * to you under the Apache License, Version 2.0 (the</em>
<a class="jxr_linenumber" name="7" href="#7">7</a>   <em class="jxr_javadoccomment"> * "License"); you may not use this file except in compliance</em>
<a class="jxr_linenumber" name="8" href="#8">8</a>   <em class="jxr_javadoccomment"> * with the License.  You may obtain a copy of the License at</em>
<a class="jxr_linenumber" name="9" href="#9">9</a>   <em class="jxr_javadoccomment"> *</em>
<a class="jxr_linenumber" name="10" href="#10">10</a>  <em class="jxr_javadoccomment"> *     <a href="http://www.apache.org/licenses/LICENSE-2.0" target="alexandria_uri">http://www.apache.org/licenses/LICENSE-2.0</a></em>
<a class="jxr_linenumber" name="11" href="#11">11</a>  <em class="jxr_javadoccomment"> *</em>
<a class="jxr_linenumber" name="12" href="#12">12</a>  <em class="jxr_javadoccomment"> * Unless required by applicable law or agreed to in writing, software</em>
<a class="jxr_linenumber" name="13" href="#13">13</a>  <em class="jxr_javadoccomment"> * distributed under the License is distributed on an "AS IS" BASIS,</em>
<a class="jxr_linenumber" name="14" href="#14">14</a>  <em class="jxr_javadoccomment"> * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.</em>
<a class="jxr_linenumber" name="15" href="#15">15</a>  <em class="jxr_javadoccomment"> * See the License for the specific language governing permissions and</em>
<a class="jxr_linenumber" name="16" href="#16">16</a>  <em class="jxr_javadoccomment"> * limitations under the License.</em>
<a class="jxr_linenumber" name="17" href="#17">17</a>  <em class="jxr_javadoccomment"> */</em>
<a class="jxr_linenumber" name="18" href="#18">18</a>  <strong class="jxr_keyword">package</strong> org.apache.hadoop.hbase.backup.example;
<a class="jxr_linenumber" name="19" href="#19">19</a>  
<a class="jxr_linenumber" name="20" href="#20">20</a>  <strong class="jxr_keyword">import</strong> <strong class="jxr_keyword">static</strong> org.junit.Assert.assertEquals;
<a class="jxr_linenumber" name="21" href="#21">21</a>  <strong class="jxr_keyword">import</strong> <strong class="jxr_keyword">static</strong> org.junit.Assert.assertFalse;
<a class="jxr_linenumber" name="22" href="#22">22</a>  <strong class="jxr_keyword">import</strong> <strong class="jxr_keyword">static</strong> org.junit.Assert.assertTrue;
<a class="jxr_linenumber" name="23" href="#23">23</a>  <strong class="jxr_keyword">import</strong> <strong class="jxr_keyword">static</strong> org.mockito.Mockito.mock;
<a class="jxr_linenumber" name="24" href="#24">24</a>  <strong class="jxr_keyword">import</strong> <strong class="jxr_keyword">static</strong> org.mockito.Mockito.when;
<a class="jxr_linenumber" name="25" href="#25">25</a>  
<a class="jxr_linenumber" name="26" href="#26">26</a>  <strong class="jxr_keyword">import</strong> java.io.IOException;
<a class="jxr_linenumber" name="27" href="#27">27</a>  <strong class="jxr_keyword">import</strong> java.util.ArrayList;
<a class="jxr_linenumber" name="28" href="#28">28</a>  <strong class="jxr_keyword">import</strong> java.util.List;
<a class="jxr_linenumber" name="29" href="#29">29</a>  <strong class="jxr_keyword">import</strong> java.util.concurrent.CountDownLatch;
<a class="jxr_linenumber" name="30" href="#30">30</a>  
<a class="jxr_linenumber" name="31" href="#31">31</a>  <strong class="jxr_keyword">import</strong> org.apache.commons.logging.Log;
<a class="jxr_linenumber" name="32" href="#32">32</a>  <strong class="jxr_keyword">import</strong> org.apache.commons.logging.LogFactory;
<a class="jxr_linenumber" name="33" href="#33">33</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.conf.Configuration;
<a class="jxr_linenumber" name="34" href="#34">34</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.fs.FileStatus;
<a class="jxr_linenumber" name="35" href="#35">35</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.fs.FileSystem;
<a class="jxr_linenumber" name="36" href="#36">36</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.fs.Path;
<a class="jxr_linenumber" name="37" href="#37">37</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.ChoreService;
<a class="jxr_linenumber" name="38" href="#38">38</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.HBaseTestingUtility;
<a class="jxr_linenumber" name="39" href="#39">39</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.HColumnDescriptor;
<a class="jxr_linenumber" name="40" href="#40">40</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.HConstants;
<a class="jxr_linenumber" name="41" href="#41">41</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.master.cleaner.DirScanPool;
<a class="jxr_linenumber" name="42" href="#42">42</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.testclassification.MediumTests;
<a class="jxr_linenumber" name="43" href="#43">43</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.Stoppable;
<a class="jxr_linenumber" name="44" href="#44">44</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.client.ClusterConnection;
<a class="jxr_linenumber" name="45" href="#45">45</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.client.ConnectionFactory;
<a class="jxr_linenumber" name="46" href="#46">46</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.client.Put;
<a class="jxr_linenumber" name="47" href="#47">47</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.master.cleaner.BaseHFileCleanerDelegate;
<a class="jxr_linenumber" name="48" href="#48">48</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.master.cleaner.HFileCleaner;
<a class="jxr_linenumber" name="49" href="#49">49</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.regionserver.CompactedHFilesDischarger;
<a class="jxr_linenumber" name="50" href="#50">50</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.regionserver.HRegion;
<a class="jxr_linenumber" name="51" href="#51">51</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.regionserver.Region;
<a class="jxr_linenumber" name="52" href="#52">52</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.regionserver.RegionServerServices;
<a class="jxr_linenumber" name="53" href="#53">53</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.regionserver.Store;
<a class="jxr_linenumber" name="54" href="#54">54</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.util.Bytes;
<a class="jxr_linenumber" name="55" href="#55">55</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.util.FSUtils;
<a class="jxr_linenumber" name="56" href="#56">56</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.util.HFileArchiveUtil;
<a class="jxr_linenumber" name="57" href="#57">57</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.util.StoppableImplementation;
<a class="jxr_linenumber" name="58" href="#58">58</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.zookeeper.ZKUtil;
<a class="jxr_linenumber" name="59" href="#59">59</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.zookeeper.ZooKeeperWatcher;
<a class="jxr_linenumber" name="60" href="#60">60</a>  <strong class="jxr_keyword">import</strong> org.apache.zookeeper.KeeperException;
<a class="jxr_linenumber" name="61" href="#61">61</a>  <strong class="jxr_keyword">import</strong> org.junit.After;
<a class="jxr_linenumber" name="62" href="#62">62</a>  <strong class="jxr_keyword">import</strong> org.junit.AfterClass;
<a class="jxr_linenumber" name="63" href="#63">63</a>  <strong class="jxr_keyword">import</strong> org.junit.BeforeClass;
<a class="jxr_linenumber" name="64" href="#64">64</a>  <strong class="jxr_keyword">import</strong> org.junit.Test;
<a class="jxr_linenumber" name="65" href="#65">65</a>  <strong class="jxr_keyword">import</strong> org.junit.experimental.categories.Category;
<a class="jxr_linenumber" name="66" href="#66">66</a>  <strong class="jxr_keyword">import</strong> org.mockito.Mockito;
<a class="jxr_linenumber" name="67" href="#67">67</a>  <strong class="jxr_keyword">import</strong> org.mockito.invocation.InvocationOnMock;
<a class="jxr_linenumber" name="68" href="#68">68</a>  <strong class="jxr_keyword">import</strong> org.mockito.stubbing.Answer;
<a class="jxr_linenumber" name="69" href="#69">69</a>  
<a class="jxr_linenumber" name="70" href="#70">70</a>  <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="71" href="#71">71</a>  <em class="jxr_javadoccomment"> * Spin up a small cluster and check that the hfiles of region are properly long-term archived as</em>
<a class="jxr_linenumber" name="72" href="#72">72</a>  <em class="jxr_javadoccomment"> * specified via the {@link ZKTableArchiveClient}.</em>
<a class="jxr_linenumber" name="73" href="#73">73</a>  <em class="jxr_javadoccomment"> */</em>
<a class="jxr_linenumber" name="74" href="#74">74</a>  @Category(MediumTests.<strong class="jxr_keyword">class</strong>)
<a class="jxr_linenumber" name="75" href="#75">75</a>  <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">class</strong> <a href="../../../../../../org/apache/hadoop/hbase/backup/example/TestZooKeeperTableArchiveClient.html">TestZooKeeperTableArchiveClient</a> {
<a class="jxr_linenumber" name="76" href="#76">76</a>  
<a class="jxr_linenumber" name="77" href="#77">77</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">final</strong> Log LOG = LogFactory.getLog(TestZooKeeperTableArchiveClient.<strong class="jxr_keyword">class</strong>);
<a class="jxr_linenumber" name="78" href="#78">78</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">final</strong> <a href="../../../../../../org/apache/hadoop/hbase/HBaseTestingUtility.html">HBaseTestingUtility</a> UTIL = HBaseTestingUtility.createLocalHTU();
<a class="jxr_linenumber" name="79" href="#79">79</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">final</strong> String STRING_TABLE_NAME = <span class="jxr_string">"test"</span>;
<a class="jxr_linenumber" name="80" href="#80">80</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">final</strong> byte[] TEST_FAM = Bytes.toBytes(<span class="jxr_string">"fam"</span>);
<a class="jxr_linenumber" name="81" href="#81">81</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">final</strong> byte[] TABLE_NAME = Bytes.toBytes(STRING_TABLE_NAME);
<a class="jxr_linenumber" name="82" href="#82">82</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> ZKTableArchiveClient archivingClient;
<a class="jxr_linenumber" name="83" href="#83">83</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">final</strong> List&lt;Path&gt; toCleanup = <strong class="jxr_keyword">new</strong> ArrayList&lt;Path&gt;();
<a class="jxr_linenumber" name="84" href="#84">84</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> ClusterConnection CONNECTION;
<a class="jxr_linenumber" name="85" href="#85">85</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> RegionServerServices rss;
<a class="jxr_linenumber" name="86" href="#86">86</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> DirScanPool POOL;
<a class="jxr_linenumber" name="87" href="#87">87</a>  
<a class="jxr_linenumber" name="88" href="#88">88</a>    <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="89" href="#89">89</a>  <em class="jxr_javadoccomment">   * Setup the config for the cluster</em>
<a class="jxr_linenumber" name="90" href="#90">90</a>  <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="91" href="#91">91</a>    @BeforeClass
<a class="jxr_linenumber" name="92" href="#92">92</a>    <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">void</strong> setupCluster() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="93" href="#93">93</a>      setupConf(UTIL.getConfiguration());
<a class="jxr_linenumber" name="94" href="#94">94</a>      UTIL.startMiniZKCluster();
<a class="jxr_linenumber" name="95" href="#95">95</a>      CONNECTION = (ClusterConnection)ConnectionFactory.createConnection(UTIL.getConfiguration());
<a class="jxr_linenumber" name="96" href="#96">96</a>      archivingClient = <strong class="jxr_keyword">new</strong> ZKTableArchiveClient(UTIL.getConfiguration(), CONNECTION);
<a class="jxr_linenumber" name="97" href="#97">97</a>      <em class="jxr_comment">// make hfile archiving node so we can archive files</em>
<a class="jxr_linenumber" name="98" href="#98">98</a>      ZooKeeperWatcher watcher = UTIL.getZooKeeperWatcher();
<a class="jxr_linenumber" name="99" href="#99">99</a>      String archivingZNode = ZKTableArchiveClient.getArchiveZNode(UTIL.getConfiguration(), watcher);
<a class="jxr_linenumber" name="100" href="#100">100</a>     ZKUtil.createWithParents(watcher, archivingZNode);
<a class="jxr_linenumber" name="101" href="#101">101</a>     rss = mock(RegionServerServices.<strong class="jxr_keyword">class</strong>);
<a class="jxr_linenumber" name="102" href="#102">102</a>     POOL= <strong class="jxr_keyword">new</strong> DirScanPool(UTIL.getConfiguration());
<a class="jxr_linenumber" name="103" href="#103">103</a>   }
<a class="jxr_linenumber" name="104" href="#104">104</a> 
<a class="jxr_linenumber" name="105" href="#105">105</a>   <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">void</strong> setupConf(Configuration conf) {
<a class="jxr_linenumber" name="106" href="#106">106</a>     <em class="jxr_comment">// only compact with 3 files</em>
<a class="jxr_linenumber" name="107" href="#107">107</a>     conf.setInt(<span class="jxr_string">"hbase.hstore.compaction.min"</span>, 3);
<a class="jxr_linenumber" name="108" href="#108">108</a>   }
<a class="jxr_linenumber" name="109" href="#109">109</a> 
<a class="jxr_linenumber" name="110" href="#110">110</a>   @After
<a class="jxr_linenumber" name="111" href="#111">111</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> tearDown() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="112" href="#112">112</a>     <strong class="jxr_keyword">try</strong> {
<a class="jxr_linenumber" name="113" href="#113">113</a>       FileSystem fs = UTIL.getTestFileSystem();
<a class="jxr_linenumber" name="114" href="#114">114</a>       <em class="jxr_comment">// cleanup each of the files/directories registered</em>
<a class="jxr_linenumber" name="115" href="#115">115</a>       <strong class="jxr_keyword">for</strong> (Path file : toCleanup) {
<a class="jxr_linenumber" name="116" href="#116">116</a>       <em class="jxr_comment">// remove the table and archive directories</em>
<a class="jxr_linenumber" name="117" href="#117">117</a>         FSUtils.delete(fs, file, <strong class="jxr_keyword">true</strong>);
<a class="jxr_linenumber" name="118" href="#118">118</a>       }
<a class="jxr_linenumber" name="119" href="#119">119</a>     } <strong class="jxr_keyword">catch</strong> (IOException e) {
<a class="jxr_linenumber" name="120" href="#120">120</a>       LOG.warn(<span class="jxr_string">"Failure to delete archive directory"</span>, e);
<a class="jxr_linenumber" name="121" href="#121">121</a>     } <strong class="jxr_keyword">finally</strong> {
<a class="jxr_linenumber" name="122" href="#122">122</a>       toCleanup.clear();
<a class="jxr_linenumber" name="123" href="#123">123</a>     }
<a class="jxr_linenumber" name="124" href="#124">124</a>     <em class="jxr_comment">// make sure that backups are off for all tables</em>
<a class="jxr_linenumber" name="125" href="#125">125</a>     archivingClient.disableHFileBackup();
<a class="jxr_linenumber" name="126" href="#126">126</a>   }
<a class="jxr_linenumber" name="127" href="#127">127</a> 
<a class="jxr_linenumber" name="128" href="#128">128</a>   @AfterClass
<a class="jxr_linenumber" name="129" href="#129">129</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">void</strong> cleanupTest() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="130" href="#130">130</a>     CONNECTION.close();
<a class="jxr_linenumber" name="131" href="#131">131</a>     UTIL.shutdownMiniZKCluster();
<a class="jxr_linenumber" name="132" href="#132">132</a>     POOL.shutdownNow();
<a class="jxr_linenumber" name="133" href="#133">133</a>   }
<a class="jxr_linenumber" name="134" href="#134">134</a> 
<a class="jxr_linenumber" name="135" href="#135">135</a>   <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="136" href="#136">136</a> <em class="jxr_javadoccomment">   * Test turning on/off archiving</em>
<a class="jxr_linenumber" name="137" href="#137">137</a> <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="138" href="#138">138</a>   @Test (timeout=300000)
<a class="jxr_linenumber" name="139" href="#139">139</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> testArchivingEnableDisable() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="140" href="#140">140</a>     <em class="jxr_comment">// 1. turn on hfile backups</em>
<a class="jxr_linenumber" name="141" href="#141">141</a>     LOG.debug(<span class="jxr_string">"----Starting archiving"</span>);
<a class="jxr_linenumber" name="142" href="#142">142</a>     archivingClient.enableHFileBackupAsync(TABLE_NAME);
<a class="jxr_linenumber" name="143" href="#143">143</a>     assertTrue(<span class="jxr_string">"Archving didn't get turned on"</span>, archivingClient
<a class="jxr_linenumber" name="144" href="#144">144</a>         .getArchivingEnabled(TABLE_NAME));
<a class="jxr_linenumber" name="145" href="#145">145</a> 
<a class="jxr_linenumber" name="146" href="#146">146</a>     <em class="jxr_comment">// 2. Turn off archiving and make sure its off</em>
<a class="jxr_linenumber" name="147" href="#147">147</a>     archivingClient.disableHFileBackup();
<a class="jxr_linenumber" name="148" href="#148">148</a>     assertFalse(<span class="jxr_string">"Archving didn't get turned off."</span>, archivingClient.getArchivingEnabled(TABLE_NAME));
<a class="jxr_linenumber" name="149" href="#149">149</a> 
<a class="jxr_linenumber" name="150" href="#150">150</a>     <em class="jxr_comment">// 3. Check enable/disable on a single table</em>
<a class="jxr_linenumber" name="151" href="#151">151</a>     archivingClient.enableHFileBackupAsync(TABLE_NAME);
<a class="jxr_linenumber" name="152" href="#152">152</a>     assertTrue(<span class="jxr_string">"Archving didn't get turned on"</span>, archivingClient
<a class="jxr_linenumber" name="153" href="#153">153</a>         .getArchivingEnabled(TABLE_NAME));
<a class="jxr_linenumber" name="154" href="#154">154</a> 
<a class="jxr_linenumber" name="155" href="#155">155</a>     <em class="jxr_comment">// 4. Turn off archiving and make sure its off</em>
<a class="jxr_linenumber" name="156" href="#156">156</a>     archivingClient.disableHFileBackup(TABLE_NAME);
<a class="jxr_linenumber" name="157" href="#157">157</a>     assertFalse(<span class="jxr_string">"Archving didn't get turned off for "</span> + STRING_TABLE_NAME,
<a class="jxr_linenumber" name="158" href="#158">158</a>       archivingClient.getArchivingEnabled(TABLE_NAME));
<a class="jxr_linenumber" name="159" href="#159">159</a>   }
<a class="jxr_linenumber" name="160" href="#160">160</a> 
<a class="jxr_linenumber" name="161" href="#161">161</a>   @Test (timeout=300000)
<a class="jxr_linenumber" name="162" href="#162">162</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> testArchivingOnSingleTable() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="163" href="#163">163</a>     createArchiveDirectory();
<a class="jxr_linenumber" name="164" href="#164">164</a>     FileSystem fs = UTIL.getTestFileSystem();
<a class="jxr_linenumber" name="165" href="#165">165</a>     Path archiveDir = getArchiveDir();
<a class="jxr_linenumber" name="166" href="#166">166</a>     Path tableDir = getTableDir(STRING_TABLE_NAME);
<a class="jxr_linenumber" name="167" href="#167">167</a>     toCleanup.add(archiveDir);
<a class="jxr_linenumber" name="168" href="#168">168</a>     toCleanup.add(tableDir);
<a class="jxr_linenumber" name="169" href="#169">169</a> 
<a class="jxr_linenumber" name="170" href="#170">170</a>     Configuration conf = UTIL.getConfiguration();
<a class="jxr_linenumber" name="171" href="#171">171</a>     <em class="jxr_comment">// setup the delegate</em>
<a class="jxr_linenumber" name="172" href="#172">172</a>     Stoppable stop = <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/TestNodeHealthCheckChore.html">StoppableImplementation</a>();
<a class="jxr_linenumber" name="173" href="#173">173</a>     HFileCleaner cleaner = setupAndCreateCleaner(conf, fs, archiveDir, stop);
<a class="jxr_linenumber" name="174" href="#174">174</a>     List&lt;BaseHFileCleanerDelegate&gt; cleaners = turnOnArchiving(STRING_TABLE_NAME, cleaner);
<a class="jxr_linenumber" name="175" href="#175">175</a>     <strong class="jxr_keyword">final</strong> LongTermArchivingHFileCleaner delegate = (LongTermArchivingHFileCleaner) cleaners.get(0);
<a class="jxr_linenumber" name="176" href="#176">176</a> 
<a class="jxr_linenumber" name="177" href="#177">177</a>     <em class="jxr_comment">// create the region</em>
<a class="jxr_linenumber" name="178" href="#178">178</a>     HColumnDescriptor hcd = <strong class="jxr_keyword">new</strong> HColumnDescriptor(TEST_FAM);
<a class="jxr_linenumber" name="179" href="#179">179</a>     HRegion region = UTIL.createTestRegion(STRING_TABLE_NAME, hcd);
<a class="jxr_linenumber" name="180" href="#180">180</a>     List&lt;Region&gt; regions = <strong class="jxr_keyword">new</strong> ArrayList&lt;Region&gt;();
<a class="jxr_linenumber" name="181" href="#181">181</a>     regions.add(region);
<a class="jxr_linenumber" name="182" href="#182">182</a>     when(rss.getOnlineRegions()).thenReturn(regions);
<a class="jxr_linenumber" name="183" href="#183">183</a>     <strong class="jxr_keyword">final</strong> CompactedHFilesDischarger compactionCleaner =
<a class="jxr_linenumber" name="184" href="#184">184</a>         <strong class="jxr_keyword">new</strong> CompactedHFilesDischarger(100, stop, rss, false);
<a class="jxr_linenumber" name="185" href="#185">185</a>     loadFlushAndCompact(region, TEST_FAM);
<a class="jxr_linenumber" name="186" href="#186">186</a>     compactionCleaner.chore();
<a class="jxr_linenumber" name="187" href="#187">187</a>     <em class="jxr_comment">// get the current hfiles in the archive directory</em>
<a class="jxr_linenumber" name="188" href="#188">188</a>     List&lt;Path&gt; files = getAllFiles(fs, archiveDir);
<a class="jxr_linenumber" name="189" href="#189">189</a>     <strong class="jxr_keyword">if</strong> (files == <strong class="jxr_keyword">null</strong>) {
<a class="jxr_linenumber" name="190" href="#190">190</a>       FSUtils.logFileSystemState(fs, UTIL.getDataTestDir(), LOG);
<a class="jxr_linenumber" name="191" href="#191">191</a>       <strong class="jxr_keyword">throw</strong> <strong class="jxr_keyword">new</strong> RuntimeException(<span class="jxr_string">"Didn't archive any files!"</span>);
<a class="jxr_linenumber" name="192" href="#192">192</a>     }
<a class="jxr_linenumber" name="193" href="#193">193</a>     CountDownLatch finished = setupCleanerWatching(delegate, cleaners, files.size());
<a class="jxr_linenumber" name="194" href="#194">194</a> 
<a class="jxr_linenumber" name="195" href="#195">195</a>     runCleaner(cleaner, finished, stop);
<a class="jxr_linenumber" name="196" href="#196">196</a> 
<a class="jxr_linenumber" name="197" href="#197">197</a>     <em class="jxr_comment">// know the cleaner ran, so now check all the files again to make sure they are still there</em>
<a class="jxr_linenumber" name="198" href="#198">198</a>     List&lt;Path&gt; archivedFiles = getAllFiles(fs, archiveDir);
<a class="jxr_linenumber" name="199" href="#199">199</a>     assertEquals(<span class="jxr_string">"Archived files changed after running archive cleaner."</span>, files, archivedFiles);
<a class="jxr_linenumber" name="200" href="#200">200</a> 
<a class="jxr_linenumber" name="201" href="#201">201</a>     <em class="jxr_comment">// but we still have the archive directory</em>
<a class="jxr_linenumber" name="202" href="#202">202</a>     assertTrue(fs.exists(HFileArchiveUtil.getArchivePath(UTIL.getConfiguration())));
<a class="jxr_linenumber" name="203" href="#203">203</a>   }
<a class="jxr_linenumber" name="204" href="#204">204</a> 
<a class="jxr_linenumber" name="205" href="#205">205</a>   <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="206" href="#206">206</a> <em class="jxr_javadoccomment">   * Test archiving/cleaning across multiple tables, where some are retained, and others aren't</em>
<a class="jxr_linenumber" name="207" href="#207">207</a> <em class="jxr_javadoccomment">   * @throws Exception on failure</em>
<a class="jxr_linenumber" name="208" href="#208">208</a> <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="209" href="#209">209</a>   @Test (timeout=300000)
<a class="jxr_linenumber" name="210" href="#210">210</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> testMultipleTables() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="211" href="#211">211</a>     createArchiveDirectory();
<a class="jxr_linenumber" name="212" href="#212">212</a>     String otherTable = <span class="jxr_string">"otherTable"</span>;
<a class="jxr_linenumber" name="213" href="#213">213</a> 
<a class="jxr_linenumber" name="214" href="#214">214</a>     FileSystem fs = UTIL.getTestFileSystem();
<a class="jxr_linenumber" name="215" href="#215">215</a>     Path archiveDir = getArchiveDir();
<a class="jxr_linenumber" name="216" href="#216">216</a>     Path tableDir = getTableDir(STRING_TABLE_NAME);
<a class="jxr_linenumber" name="217" href="#217">217</a>     Path otherTableDir = getTableDir(otherTable);
<a class="jxr_linenumber" name="218" href="#218">218</a> 
<a class="jxr_linenumber" name="219" href="#219">219</a>     <em class="jxr_comment">// register cleanup for the created directories</em>
<a class="jxr_linenumber" name="220" href="#220">220</a>     toCleanup.add(archiveDir);
<a class="jxr_linenumber" name="221" href="#221">221</a>     toCleanup.add(tableDir);
<a class="jxr_linenumber" name="222" href="#222">222</a>     toCleanup.add(otherTableDir);
<a class="jxr_linenumber" name="223" href="#223">223</a>     Configuration conf = UTIL.getConfiguration();
<a class="jxr_linenumber" name="224" href="#224">224</a>     <em class="jxr_comment">// setup the delegate</em>
<a class="jxr_linenumber" name="225" href="#225">225</a>     Stoppable stop = <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/TestNodeHealthCheckChore.html">StoppableImplementation</a>();
<a class="jxr_linenumber" name="226" href="#226">226</a>     <strong class="jxr_keyword">final</strong> ChoreService choreService = <strong class="jxr_keyword">new</strong> ChoreService(<span class="jxr_string">"TEST_SERVER_NAME"</span>);
<a class="jxr_linenumber" name="227" href="#227">227</a>     HFileCleaner cleaner = setupAndCreateCleaner(conf, fs, archiveDir, stop);
<a class="jxr_linenumber" name="228" href="#228">228</a>     List&lt;BaseHFileCleanerDelegate&gt; cleaners = turnOnArchiving(STRING_TABLE_NAME, cleaner);
<a class="jxr_linenumber" name="229" href="#229">229</a>     <strong class="jxr_keyword">final</strong> LongTermArchivingHFileCleaner delegate = (LongTermArchivingHFileCleaner) cleaners.get(0);
<a class="jxr_linenumber" name="230" href="#230">230</a>     <em class="jxr_comment">// create the region</em>
<a class="jxr_linenumber" name="231" href="#231">231</a>     HColumnDescriptor hcd = <strong class="jxr_keyword">new</strong> HColumnDescriptor(TEST_FAM);
<a class="jxr_linenumber" name="232" href="#232">232</a>     HRegion region = UTIL.createTestRegion(STRING_TABLE_NAME, hcd);
<a class="jxr_linenumber" name="233" href="#233">233</a>     List&lt;Region&gt; regions = <strong class="jxr_keyword">new</strong> ArrayList&lt;Region&gt;();
<a class="jxr_linenumber" name="234" href="#234">234</a>     regions.add(region);
<a class="jxr_linenumber" name="235" href="#235">235</a>     when(rss.getOnlineRegions()).thenReturn(regions);
<a class="jxr_linenumber" name="236" href="#236">236</a>     <strong class="jxr_keyword">final</strong> CompactedHFilesDischarger compactionCleaner =
<a class="jxr_linenumber" name="237" href="#237">237</a>         <strong class="jxr_keyword">new</strong> CompactedHFilesDischarger(100, stop, rss, false);
<a class="jxr_linenumber" name="238" href="#238">238</a>     loadFlushAndCompact(region, TEST_FAM);
<a class="jxr_linenumber" name="239" href="#239">239</a>     compactionCleaner.chore();
<a class="jxr_linenumber" name="240" href="#240">240</a>     <em class="jxr_comment">// create the another table that we don't archive</em>
<a class="jxr_linenumber" name="241" href="#241">241</a>     hcd = <strong class="jxr_keyword">new</strong> HColumnDescriptor(TEST_FAM);
<a class="jxr_linenumber" name="242" href="#242">242</a>     HRegion otherRegion = UTIL.createTestRegion(otherTable, hcd);
<a class="jxr_linenumber" name="243" href="#243">243</a>     regions = <strong class="jxr_keyword">new</strong> ArrayList&lt;Region&gt;();
<a class="jxr_linenumber" name="244" href="#244">244</a>     regions.add(otherRegion);
<a class="jxr_linenumber" name="245" href="#245">245</a>     when(rss.getOnlineRegions()).thenReturn(regions);
<a class="jxr_linenumber" name="246" href="#246">246</a>     <strong class="jxr_keyword">final</strong> CompactedHFilesDischarger compactionCleaner1 = <strong class="jxr_keyword">new</strong> CompactedHFilesDischarger(100, stop,
<a class="jxr_linenumber" name="247" href="#247">247</a>         rss, false);
<a class="jxr_linenumber" name="248" href="#248">248</a>     loadFlushAndCompact(otherRegion, TEST_FAM);
<a class="jxr_linenumber" name="249" href="#249">249</a>     compactionCleaner1.chore();
<a class="jxr_linenumber" name="250" href="#250">250</a>     <em class="jxr_comment">// get the current hfiles in the archive directory</em>
<a class="jxr_linenumber" name="251" href="#251">251</a>     <em class="jxr_comment">// Should  be archived</em>
<a class="jxr_linenumber" name="252" href="#252">252</a>     List&lt;Path&gt; files = getAllFiles(fs, archiveDir);
<a class="jxr_linenumber" name="253" href="#253">253</a>     <strong class="jxr_keyword">if</strong> (files == <strong class="jxr_keyword">null</strong>) {
<a class="jxr_linenumber" name="254" href="#254">254</a>       FSUtils.logFileSystemState(fs, archiveDir, LOG);
<a class="jxr_linenumber" name="255" href="#255">255</a>       <strong class="jxr_keyword">throw</strong> <strong class="jxr_keyword">new</strong> RuntimeException(<span class="jxr_string">"Didn't load archive any files!"</span>);
<a class="jxr_linenumber" name="256" href="#256">256</a>     }
<a class="jxr_linenumber" name="257" href="#257">257</a> 
<a class="jxr_linenumber" name="258" href="#258">258</a>     <em class="jxr_comment">// make sure we have files from both tables</em>
<a class="jxr_linenumber" name="259" href="#259">259</a>     <strong class="jxr_keyword">int</strong> initialCountForPrimary = 0;
<a class="jxr_linenumber" name="260" href="#260">260</a>     <strong class="jxr_keyword">int</strong> initialCountForOtherTable = 0;
<a class="jxr_linenumber" name="261" href="#261">261</a>     <strong class="jxr_keyword">for</strong> (Path file : files) {
<a class="jxr_linenumber" name="262" href="#262">262</a>       String tableName = file.getParent().getParent().getParent().getName();
<a class="jxr_linenumber" name="263" href="#263">263</a>       <em class="jxr_comment">// check to which table this file belongs</em>
<a class="jxr_linenumber" name="264" href="#264">264</a>       <strong class="jxr_keyword">if</strong> (tableName.equals(otherTable)) initialCountForOtherTable++;
<a class="jxr_linenumber" name="265" href="#265">265</a>       <strong class="jxr_keyword">else</strong> <strong class="jxr_keyword">if</strong> (tableName.equals(STRING_TABLE_NAME)) initialCountForPrimary++;
<a class="jxr_linenumber" name="266" href="#266">266</a>     }
<a class="jxr_linenumber" name="267" href="#267">267</a> 
<a class="jxr_linenumber" name="268" href="#268">268</a>     assertTrue(<span class="jxr_string">"Didn't archive files for:"</span> + STRING_TABLE_NAME, initialCountForPrimary &gt; 0);
<a class="jxr_linenumber" name="269" href="#269">269</a>     assertTrue(<span class="jxr_string">"Didn't archive files for:"</span> + otherTable, initialCountForOtherTable &gt; 0);
<a class="jxr_linenumber" name="270" href="#270">270</a> 
<a class="jxr_linenumber" name="271" href="#271">271</a>     <em class="jxr_comment">// run the cleaners, checking for each of the directories + files (both should be deleted and</em>
<a class="jxr_linenumber" name="272" href="#272">272</a>     <em class="jxr_comment">// need to be checked) in 'otherTable' and the files (which should be retained) in the 'table'</em>
<a class="jxr_linenumber" name="273" href="#273">273</a>     CountDownLatch finished = setupCleanerWatching(delegate, cleaners, files.size() + 3);
<a class="jxr_linenumber" name="274" href="#274">274</a>     <em class="jxr_comment">// run the cleaner</em>
<a class="jxr_linenumber" name="275" href="#275">275</a>     choreService.scheduleChore(cleaner);
<a class="jxr_linenumber" name="276" href="#276">276</a>     <em class="jxr_comment">// wait for the cleaner to check all the files</em>
<a class="jxr_linenumber" name="277" href="#277">277</a>     finished.await();
<a class="jxr_linenumber" name="278" href="#278">278</a>     <em class="jxr_comment">// stop the cleaner</em>
<a class="jxr_linenumber" name="279" href="#279">279</a>     stop.stop(<span class="jxr_string">""</span>);
<a class="jxr_linenumber" name="280" href="#280">280</a> 
<a class="jxr_linenumber" name="281" href="#281">281</a>     <em class="jxr_comment">// know the cleaner ran, so now check all the files again to make sure they are still there</em>
<a class="jxr_linenumber" name="282" href="#282">282</a>     List&lt;Path&gt; archivedFiles = getAllFiles(fs, archiveDir);
<a class="jxr_linenumber" name="283" href="#283">283</a>     <strong class="jxr_keyword">int</strong> archivedForPrimary = 0;
<a class="jxr_linenumber" name="284" href="#284">284</a>     <strong class="jxr_keyword">for</strong>(Path file: archivedFiles) {
<a class="jxr_linenumber" name="285" href="#285">285</a>       String tableName = file.getParent().getParent().getParent().getName();
<a class="jxr_linenumber" name="286" href="#286">286</a>       <em class="jxr_comment">// ensure we don't have files from the non-archived table</em>
<a class="jxr_linenumber" name="287" href="#287">287</a>       assertFalse(<span class="jxr_string">"Have a file from the non-archived table: "</span> + file, tableName.equals(otherTable));
<a class="jxr_linenumber" name="288" href="#288">288</a>       <strong class="jxr_keyword">if</strong> (tableName.equals(STRING_TABLE_NAME)) archivedForPrimary++;
<a class="jxr_linenumber" name="289" href="#289">289</a>     }
<a class="jxr_linenumber" name="290" href="#290">290</a> 
<a class="jxr_linenumber" name="291" href="#291">291</a>     assertEquals(<span class="jxr_string">"Not all archived files for the primary table were retained."</span>, initialCountForPrimary,
<a class="jxr_linenumber" name="292" href="#292">292</a>       archivedForPrimary);
<a class="jxr_linenumber" name="293" href="#293">293</a> 
<a class="jxr_linenumber" name="294" href="#294">294</a>     <em class="jxr_comment">// but we still have the archive directory</em>
<a class="jxr_linenumber" name="295" href="#295">295</a>     assertTrue(<span class="jxr_string">"Archive directory was deleted via archiver"</span>, fs.exists(archiveDir));
<a class="jxr_linenumber" name="296" href="#296">296</a>   }
<a class="jxr_linenumber" name="297" href="#297">297</a> 
<a class="jxr_linenumber" name="298" href="#298">298</a> 
<a class="jxr_linenumber" name="299" href="#299">299</a>   <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">void</strong> createArchiveDirectory() <strong class="jxr_keyword">throws</strong> IOException {
<a class="jxr_linenumber" name="300" href="#300">300</a>     <em class="jxr_comment">//create the archive and test directory</em>
<a class="jxr_linenumber" name="301" href="#301">301</a>     FileSystem fs = UTIL.getTestFileSystem();
<a class="jxr_linenumber" name="302" href="#302">302</a>     Path archiveDir = getArchiveDir();
<a class="jxr_linenumber" name="303" href="#303">303</a>     fs.mkdirs(archiveDir);
<a class="jxr_linenumber" name="304" href="#304">304</a>   }
<a class="jxr_linenumber" name="305" href="#305">305</a> 
<a class="jxr_linenumber" name="306" href="#306">306</a>   <strong class="jxr_keyword">private</strong> Path getArchiveDir() <strong class="jxr_keyword">throws</strong> IOException {
<a class="jxr_linenumber" name="307" href="#307">307</a>     <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">new</strong> Path(UTIL.getDataTestDir(), HConstants.HFILE_ARCHIVE_DIRECTORY);
<a class="jxr_linenumber" name="308" href="#308">308</a>   }
<a class="jxr_linenumber" name="309" href="#309">309</a> 
<a class="jxr_linenumber" name="310" href="#310">310</a>   <strong class="jxr_keyword">private</strong> Path getTableDir(String tableName) <strong class="jxr_keyword">throws</strong> IOException {
<a class="jxr_linenumber" name="311" href="#311">311</a>     Path testDataDir = UTIL.getDataTestDir();
<a class="jxr_linenumber" name="312" href="#312">312</a>     FSUtils.setRootDir(UTIL.getConfiguration(), testDataDir);
<a class="jxr_linenumber" name="313" href="#313">313</a>     <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">new</strong> Path(testDataDir, tableName);
<a class="jxr_linenumber" name="314" href="#314">314</a>   }
<a class="jxr_linenumber" name="315" href="#315">315</a> 
<a class="jxr_linenumber" name="316" href="#316">316</a>   <strong class="jxr_keyword">private</strong> HFileCleaner setupAndCreateCleaner(Configuration conf, FileSystem fs, Path archiveDir,
<a class="jxr_linenumber" name="317" href="#317">317</a>       Stoppable stop) {
<a class="jxr_linenumber" name="318" href="#318">318</a>     conf.setStrings(HFileCleaner.MASTER_HFILE_CLEANER_PLUGINS,
<a class="jxr_linenumber" name="319" href="#319">319</a>       LongTermArchivingHFileCleaner.<strong class="jxr_keyword">class</strong>.getCanonicalName());
<a class="jxr_linenumber" name="320" href="#320">320</a>     <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">new</strong> HFileCleaner(1000, stop, conf, fs, archiveDir, POOL);
<a class="jxr_linenumber" name="321" href="#321">321</a>   }
<a class="jxr_linenumber" name="322" href="#322">322</a> 
<a class="jxr_linenumber" name="323" href="#323">323</a>   <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="324" href="#324">324</a> <em class="jxr_javadoccomment">   * Start archiving table for given hfile cleaner</em>
<a class="jxr_linenumber" name="325" href="#325">325</a> <em class="jxr_javadoccomment">   * @param tableName table to archive</em>
<a class="jxr_linenumber" name="326" href="#326">326</a> <em class="jxr_javadoccomment">   * @param cleaner cleaner to check to make sure change propagated</em>
<a class="jxr_linenumber" name="327" href="#327">327</a> <em class="jxr_javadoccomment">   * @return underlying {@link LongTermArchivingHFileCleaner} that is managing archiving</em>
<a class="jxr_linenumber" name="328" href="#328">328</a> <em class="jxr_javadoccomment">   * @throws IOException on failure</em>
<a class="jxr_linenumber" name="329" href="#329">329</a> <em class="jxr_javadoccomment">   * @throws KeeperException on failure</em>
<a class="jxr_linenumber" name="330" href="#330">330</a> <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="331" href="#331">331</a>   <strong class="jxr_keyword">private</strong> List&lt;BaseHFileCleanerDelegate&gt; turnOnArchiving(String tableName, HFileCleaner cleaner)
<a class="jxr_linenumber" name="332" href="#332">332</a>       <strong class="jxr_keyword">throws</strong> IOException, KeeperException {
<a class="jxr_linenumber" name="333" href="#333">333</a>     <em class="jxr_comment">// turn on hfile retention</em>
<a class="jxr_linenumber" name="334" href="#334">334</a>     LOG.debug(<span class="jxr_string">"----Starting archiving for table:"</span> + tableName);
<a class="jxr_linenumber" name="335" href="#335">335</a>     archivingClient.enableHFileBackupAsync(Bytes.toBytes(tableName));
<a class="jxr_linenumber" name="336" href="#336">336</a>     assertTrue(<span class="jxr_string">"Archving didn't get turned on"</span>, archivingClient.getArchivingEnabled(tableName));
<a class="jxr_linenumber" name="337" href="#337">337</a> 
<a class="jxr_linenumber" name="338" href="#338">338</a>     <em class="jxr_comment">// wait for the archiver to get the notification</em>
<a class="jxr_linenumber" name="339" href="#339">339</a>     List&lt;BaseHFileCleanerDelegate&gt; cleaners = cleaner.getDelegatesForTesting();
<a class="jxr_linenumber" name="340" href="#340">340</a>     LongTermArchivingHFileCleaner delegate = (LongTermArchivingHFileCleaner) cleaners.get(0);
<a class="jxr_linenumber" name="341" href="#341">341</a>     <strong class="jxr_keyword">while</strong> (!delegate.archiveTracker.keepHFiles(STRING_TABLE_NAME)) {
<a class="jxr_linenumber" name="342" href="#342">342</a>       <em class="jxr_comment">// spin until propagation - should be fast</em>
<a class="jxr_linenumber" name="343" href="#343">343</a>     }
<a class="jxr_linenumber" name="344" href="#344">344</a>     <strong class="jxr_keyword">return</strong> cleaners;
<a class="jxr_linenumber" name="345" href="#345">345</a>   }
<a class="jxr_linenumber" name="346" href="#346">346</a> 
<a class="jxr_linenumber" name="347" href="#347">347</a>   <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="348" href="#348">348</a> <em class="jxr_javadoccomment">   * Spy on the {@link LongTermArchivingHFileCleaner} to ensure we can catch when the cleaner has</em>
<a class="jxr_linenumber" name="349" href="#349">349</a> <em class="jxr_javadoccomment">   * seen all the files</em>
<a class="jxr_linenumber" name="350" href="#350">350</a> <em class="jxr_javadoccomment">   * @return a {@link CountDownLatch} to wait on that releases when the cleaner has been called at</em>
<a class="jxr_linenumber" name="351" href="#351">351</a> <em class="jxr_javadoccomment">   *         least the expected number of times.</em>
<a class="jxr_linenumber" name="352" href="#352">352</a> <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="353" href="#353">353</a>   <strong class="jxr_keyword">private</strong> CountDownLatch setupCleanerWatching(LongTermArchivingHFileCleaner cleaner,
<a class="jxr_linenumber" name="354" href="#354">354</a>       List&lt;BaseHFileCleanerDelegate&gt; cleaners, <strong class="jxr_keyword">final</strong> <strong class="jxr_keyword">int</strong> expected) {
<a class="jxr_linenumber" name="355" href="#355">355</a>     <em class="jxr_comment">// replace the cleaner with one that we can can check</em>
<a class="jxr_linenumber" name="356" href="#356">356</a>     BaseHFileCleanerDelegate delegateSpy = Mockito.spy(cleaner);
<a class="jxr_linenumber" name="357" href="#357">357</a>     <strong class="jxr_keyword">final</strong> <strong class="jxr_keyword">int</strong>[] counter = <strong class="jxr_keyword">new</strong> <strong class="jxr_keyword">int</strong>[] { 0 };
<a class="jxr_linenumber" name="358" href="#358">358</a>     <strong class="jxr_keyword">final</strong> CountDownLatch finished = <strong class="jxr_keyword">new</strong> CountDownLatch(1);
<a class="jxr_linenumber" name="359" href="#359">359</a>     Mockito.doAnswer(<strong class="jxr_keyword">new</strong> Answer&lt;Iterable&lt;FileStatus&gt;&gt;() {
<a class="jxr_linenumber" name="360" href="#360">360</a> 
<a class="jxr_linenumber" name="361" href="#361">361</a>       @Override
<a class="jxr_linenumber" name="362" href="#362">362</a>       <strong class="jxr_keyword">public</strong> Iterable&lt;FileStatus&gt; answer(InvocationOnMock invocation) <strong class="jxr_keyword">throws</strong> Throwable {
<a class="jxr_linenumber" name="363" href="#363">363</a>         counter[0]++;
<a class="jxr_linenumber" name="364" href="#364">364</a>         LOG.debug(counter[0] + <span class="jxr_string">"/ "</span> + expected + <span class="jxr_string">") Wrapping call to getDeletableFiles for files: "</span>
<a class="jxr_linenumber" name="365" href="#365">365</a>             + invocation.getArguments()[0]);
<a class="jxr_linenumber" name="366" href="#366">366</a> 
<a class="jxr_linenumber" name="367" href="#367">367</a>         @SuppressWarnings(<span class="jxr_string">"unchecked"</span>)
<a class="jxr_linenumber" name="368" href="#368">368</a>         Iterable&lt;FileStatus&gt; ret = (Iterable&lt;FileStatus&gt;) invocation.callRealMethod();
<a class="jxr_linenumber" name="369" href="#369">369</a>         <strong class="jxr_keyword">if</strong> (counter[0] &gt;= expected) finished.countDown();
<a class="jxr_linenumber" name="370" href="#370">370</a>         <strong class="jxr_keyword">return</strong> ret;
<a class="jxr_linenumber" name="371" href="#371">371</a>       }
<a class="jxr_linenumber" name="372" href="#372">372</a>     }).when(delegateSpy).getDeletableFiles(Mockito.anyListOf(FileStatus.<strong class="jxr_keyword">class</strong>));
<a class="jxr_linenumber" name="373" href="#373">373</a>     cleaners.set(0, delegateSpy);
<a class="jxr_linenumber" name="374" href="#374">374</a> 
<a class="jxr_linenumber" name="375" href="#375">375</a>     <strong class="jxr_keyword">return</strong> finished;
<a class="jxr_linenumber" name="376" href="#376">376</a>   }
<a class="jxr_linenumber" name="377" href="#377">377</a> 
<a class="jxr_linenumber" name="378" href="#378">378</a>   <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="379" href="#379">379</a> <em class="jxr_javadoccomment">   * Get all the files (non-directory entries) in the file system under the passed directory</em>
<a class="jxr_linenumber" name="380" href="#380">380</a> <em class="jxr_javadoccomment">   * @param dir directory to investigate</em>
<a class="jxr_linenumber" name="381" href="#381">381</a> <em class="jxr_javadoccomment">   * @return all files under the directory</em>
<a class="jxr_linenumber" name="382" href="#382">382</a> <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="383" href="#383">383</a>   <strong class="jxr_keyword">private</strong> List&lt;Path&gt; getAllFiles(FileSystem fs, Path dir) <strong class="jxr_keyword">throws</strong> IOException {
<a class="jxr_linenumber" name="384" href="#384">384</a>     FileStatus[] files = FSUtils.listStatus(fs, dir, <strong class="jxr_keyword">null</strong>);
<a class="jxr_linenumber" name="385" href="#385">385</a>     <strong class="jxr_keyword">if</strong> (files == <strong class="jxr_keyword">null</strong>) {
<a class="jxr_linenumber" name="386" href="#386">386</a>       LOG.warn(<span class="jxr_string">"No files under:"</span> + dir);
<a class="jxr_linenumber" name="387" href="#387">387</a>       <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="388" href="#388">388</a>     }
<a class="jxr_linenumber" name="389" href="#389">389</a> 
<a class="jxr_linenumber" name="390" href="#390">390</a>     List&lt;Path&gt; allFiles = <strong class="jxr_keyword">new</strong> ArrayList&lt;Path&gt;();
<a class="jxr_linenumber" name="391" href="#391">391</a>     <strong class="jxr_keyword">for</strong> (FileStatus file : files) {
<a class="jxr_linenumber" name="392" href="#392">392</a>       <strong class="jxr_keyword">if</strong> (file.isDirectory()) {
<a class="jxr_linenumber" name="393" href="#393">393</a>         List&lt;Path&gt; subFiles = getAllFiles(fs, file.getPath());
<a class="jxr_linenumber" name="394" href="#394">394</a>         <strong class="jxr_keyword">if</strong> (subFiles != <strong class="jxr_keyword">null</strong>) allFiles.addAll(subFiles);
<a class="jxr_linenumber" name="395" href="#395">395</a>         <strong class="jxr_keyword">continue</strong>;
<a class="jxr_linenumber" name="396" href="#396">396</a>       }
<a class="jxr_linenumber" name="397" href="#397">397</a>       allFiles.add(file.getPath());
<a class="jxr_linenumber" name="398" href="#398">398</a>     }
<a class="jxr_linenumber" name="399" href="#399">399</a>     <strong class="jxr_keyword">return</strong> allFiles;
<a class="jxr_linenumber" name="400" href="#400">400</a>   }
<a class="jxr_linenumber" name="401" href="#401">401</a> 
<a class="jxr_linenumber" name="402" href="#402">402</a>   <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">void</strong> loadFlushAndCompact(Region region, byte[] family) <strong class="jxr_keyword">throws</strong> IOException {
<a class="jxr_linenumber" name="403" href="#403">403</a>     <em class="jxr_comment">// create two hfiles in the region</em>
<a class="jxr_linenumber" name="404" href="#404">404</a>     createHFileInRegion(region, family);
<a class="jxr_linenumber" name="405" href="#405">405</a>     createHFileInRegion(region, family);
<a class="jxr_linenumber" name="406" href="#406">406</a> 
<a class="jxr_linenumber" name="407" href="#407">407</a>     Store s = region.getStore(family);
<a class="jxr_linenumber" name="408" href="#408">408</a>     <strong class="jxr_keyword">int</strong> count = s.getStorefilesCount();
<a class="jxr_linenumber" name="409" href="#409">409</a>     assertTrue(<span class="jxr_string">"Don't have the expected store files, wanted &gt;= 2 store files, but was:"</span> + count,
<a class="jxr_linenumber" name="410" href="#410">410</a>       count &gt;= 2);
<a class="jxr_linenumber" name="411" href="#411">411</a> 
<a class="jxr_linenumber" name="412" href="#412">412</a>     <em class="jxr_comment">// compact the two files into one file to get files in the archive</em>
<a class="jxr_linenumber" name="413" href="#413">413</a>     LOG.debug(<span class="jxr_string">"Compacting stores"</span>);
<a class="jxr_linenumber" name="414" href="#414">414</a>     region.compact(<strong class="jxr_keyword">true</strong>);
<a class="jxr_linenumber" name="415" href="#415">415</a>   }
<a class="jxr_linenumber" name="416" href="#416">416</a> 
<a class="jxr_linenumber" name="417" href="#417">417</a>   <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="418" href="#418">418</a> <em class="jxr_javadoccomment">   * Create a new hfile in the passed region</em>
<a class="jxr_linenumber" name="419" href="#419">419</a> <em class="jxr_javadoccomment">   * @param region region to operate on</em>
<a class="jxr_linenumber" name="420" href="#420">420</a> <em class="jxr_javadoccomment">   * @param columnFamily family for which to add data</em>
<a class="jxr_linenumber" name="421" href="#421">421</a> <em class="jxr_javadoccomment">   * @throws IOException</em>
<a class="jxr_linenumber" name="422" href="#422">422</a> <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="423" href="#423">423</a>   <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">void</strong> createHFileInRegion(Region region, byte[] columnFamily) <strong class="jxr_keyword">throws</strong> IOException {
<a class="jxr_linenumber" name="424" href="#424">424</a>     <em class="jxr_comment">// put one row in the region</em>
<a class="jxr_linenumber" name="425" href="#425">425</a>     Put p = <strong class="jxr_keyword">new</strong> Put(Bytes.toBytes(<span class="jxr_string">"row"</span>));
<a class="jxr_linenumber" name="426" href="#426">426</a>     p.add(columnFamily, Bytes.toBytes(<span class="jxr_string">"Qual"</span>), Bytes.toBytes(<span class="jxr_string">"v1"</span>));
<a class="jxr_linenumber" name="427" href="#427">427</a>     region.put(p);
<a class="jxr_linenumber" name="428" href="#428">428</a>     <em class="jxr_comment">// flush the region to make a store file</em>
<a class="jxr_linenumber" name="429" href="#429">429</a>     region.flush(<strong class="jxr_keyword">true</strong>);
<a class="jxr_linenumber" name="430" href="#430">430</a>   }
<a class="jxr_linenumber" name="431" href="#431">431</a> 
<a class="jxr_linenumber" name="432" href="#432">432</a>   <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="433" href="#433">433</a> <em class="jxr_javadoccomment">   * @param cleaner</em>
<a class="jxr_linenumber" name="434" href="#434">434</a> <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="435" href="#435">435</a>   <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">void</strong> runCleaner(HFileCleaner cleaner, CountDownLatch finished, Stoppable stop)
<a class="jxr_linenumber" name="436" href="#436">436</a>       <strong class="jxr_keyword">throws</strong> InterruptedException {
<a class="jxr_linenumber" name="437" href="#437">437</a>     <strong class="jxr_keyword">final</strong> ChoreService choreService = <strong class="jxr_keyword">new</strong> ChoreService(<span class="jxr_string">"CLEANER_SERVER_NAME"</span>);
<a class="jxr_linenumber" name="438" href="#438">438</a>     <em class="jxr_comment">// run the cleaner</em>
<a class="jxr_linenumber" name="439" href="#439">439</a>     choreService.scheduleChore(cleaner);
<a class="jxr_linenumber" name="440" href="#440">440</a>     <em class="jxr_comment">// wait for the cleaner to check all the files</em>
<a class="jxr_linenumber" name="441" href="#441">441</a>     finished.await();
<a class="jxr_linenumber" name="442" href="#442">442</a>     <em class="jxr_comment">// stop the cleaner</em>
<a class="jxr_linenumber" name="443" href="#443">443</a>     stop.stop(<span class="jxr_string">""</span>);
<a class="jxr_linenumber" name="444" href="#444">444</a>   }
<a class="jxr_linenumber" name="445" href="#445">445</a> }
</pre>
<hr/><div id="footer">This page was automatically generated by <a href="http://maven.apache.org/">Maven</a></div></body>
</html>

