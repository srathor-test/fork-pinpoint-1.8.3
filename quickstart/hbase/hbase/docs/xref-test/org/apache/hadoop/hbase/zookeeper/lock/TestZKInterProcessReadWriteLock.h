<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8" />
<title>TestZKInterProcessReadWriteLock xref</title>
<link type="text/css" rel="stylesheet" href="../../../../../../stylesheet.css" />
</head>
<body>
<div id="overview"><a href="../../../../../../../testapidocs/org/apache/hadoop/hbase/zookeeper/lock/TestZKInterProcessReadWriteLock.html">View Javadoc</a></div><pre>

<a class="jxr_linenumber" name="1" href="#1">1</a>   <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="2" href="#2">2</a>   <em class="jxr_javadoccomment"> * Copyright The Apache Software Foundation</em>
<a class="jxr_linenumber" name="3" href="#3">3</a>   <em class="jxr_javadoccomment"> *</em>
<a class="jxr_linenumber" name="4" href="#4">4</a>   <em class="jxr_javadoccomment"> * Licensed to the Apache Software Foundation (ASF) under one</em>
<a class="jxr_linenumber" name="5" href="#5">5</a>   <em class="jxr_javadoccomment"> * or more contributor license agreements.  See the NOTICE file</em>
<a class="jxr_linenumber" name="6" href="#6">6</a>   <em class="jxr_javadoccomment"> * distributed with this work for additional information</em>
<a class="jxr_linenumber" name="7" href="#7">7</a>   <em class="jxr_javadoccomment"> * regarding copyright ownership.  The ASF licenses this file</em>
<a class="jxr_linenumber" name="8" href="#8">8</a>   <em class="jxr_javadoccomment"> * to you under the Apache License, Version 2.0 (the</em>
<a class="jxr_linenumber" name="9" href="#9">9</a>   <em class="jxr_javadoccomment"> * "License"); you may not use this file except in compliance</em>
<a class="jxr_linenumber" name="10" href="#10">10</a>  <em class="jxr_javadoccomment"> * with the License.  You may obtain a copy of the License at</em>
<a class="jxr_linenumber" name="11" href="#11">11</a>  <em class="jxr_javadoccomment"> *</em>
<a class="jxr_linenumber" name="12" href="#12">12</a>  <em class="jxr_javadoccomment"> *     <a href="http://www.apache.org/licenses/LICENSE-2.0" target="alexandria_uri">http://www.apache.org/licenses/LICENSE-2.0</a></em>
<a class="jxr_linenumber" name="13" href="#13">13</a>  <em class="jxr_javadoccomment"> *</em>
<a class="jxr_linenumber" name="14" href="#14">14</a>  <em class="jxr_javadoccomment"> * Unless required by applicable law or agreed to in writing, software</em>
<a class="jxr_linenumber" name="15" href="#15">15</a>  <em class="jxr_javadoccomment"> * distributed under the License is distributed on an "AS IS" BASIS,</em>
<a class="jxr_linenumber" name="16" href="#16">16</a>  <em class="jxr_javadoccomment"> * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.</em>
<a class="jxr_linenumber" name="17" href="#17">17</a>  <em class="jxr_javadoccomment"> * See the License for the specific language governing permissions and</em>
<a class="jxr_linenumber" name="18" href="#18">18</a>  <em class="jxr_javadoccomment"> * limitations under the License.</em>
<a class="jxr_linenumber" name="19" href="#19">19</a>  <em class="jxr_javadoccomment"> */</em>
<a class="jxr_linenumber" name="20" href="#20">20</a>  <strong class="jxr_keyword">package</strong> org.apache.hadoop.hbase.zookeeper.lock;
<a class="jxr_linenumber" name="21" href="#21">21</a>  
<a class="jxr_linenumber" name="22" href="#22">22</a>  <strong class="jxr_keyword">import</strong> <strong class="jxr_keyword">static</strong> org.junit.Assert.assertEquals;
<a class="jxr_linenumber" name="23" href="#23">23</a>  <strong class="jxr_keyword">import</strong> <strong class="jxr_keyword">static</strong> org.junit.Assert.assertFalse;
<a class="jxr_linenumber" name="24" href="#24">24</a>  <strong class="jxr_keyword">import</strong> <strong class="jxr_keyword">static</strong> org.junit.Assert.assertTrue;
<a class="jxr_linenumber" name="25" href="#25">25</a>  
<a class="jxr_linenumber" name="26" href="#26">26</a>  <strong class="jxr_keyword">import</strong> java.io.IOException;
<a class="jxr_linenumber" name="27" href="#27">27</a>  <strong class="jxr_keyword">import</strong> java.io.InterruptedIOException;
<a class="jxr_linenumber" name="28" href="#28">28</a>  <strong class="jxr_keyword">import</strong> java.util.List;
<a class="jxr_linenumber" name="29" href="#29">29</a>  <strong class="jxr_keyword">import</strong> java.util.concurrent.Callable;
<a class="jxr_linenumber" name="30" href="#30">30</a>  <strong class="jxr_keyword">import</strong> java.util.concurrent.CountDownLatch;
<a class="jxr_linenumber" name="31" href="#31">31</a>  <strong class="jxr_keyword">import</strong> java.util.concurrent.ExecutorService;
<a class="jxr_linenumber" name="32" href="#32">32</a>  <strong class="jxr_keyword">import</strong> java.util.concurrent.Executors;
<a class="jxr_linenumber" name="33" href="#33">33</a>  <strong class="jxr_keyword">import</strong> java.util.concurrent.Future;
<a class="jxr_linenumber" name="34" href="#34">34</a>  <strong class="jxr_keyword">import</strong> java.util.concurrent.atomic.AtomicBoolean;
<a class="jxr_linenumber" name="35" href="#35">35</a>  <strong class="jxr_keyword">import</strong> java.util.concurrent.atomic.AtomicInteger;
<a class="jxr_linenumber" name="36" href="#36">36</a>  
<a class="jxr_linenumber" name="37" href="#37">37</a>  <strong class="jxr_keyword">import</strong> org.apache.commons.logging.Log;
<a class="jxr_linenumber" name="38" href="#38">38</a>  <strong class="jxr_keyword">import</strong> org.apache.commons.logging.LogFactory;
<a class="jxr_linenumber" name="39" href="#39">39</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.conf.Configuration;
<a class="jxr_linenumber" name="40" href="#40">40</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.DaemonThreadFactory;
<a class="jxr_linenumber" name="41" href="#41">41</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.HBaseTestingUtility;
<a class="jxr_linenumber" name="42" href="#42">42</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.HConstants;
<a class="jxr_linenumber" name="43" href="#43">43</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.InterProcessLock;
<a class="jxr_linenumber" name="44" href="#44">44</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.InterProcessLock.MetadataHandler;
<a class="jxr_linenumber" name="45" href="#45">45</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.testclassification.MediumTests;
<a class="jxr_linenumber" name="46" href="#46">46</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.MultithreadedTestUtil;
<a class="jxr_linenumber" name="47" href="#47">47</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.util.Bytes;
<a class="jxr_linenumber" name="48" href="#48">48</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.zookeeper.ZKUtil;
<a class="jxr_linenumber" name="49" href="#49">49</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.zookeeper.ZooKeeperWatcher;
<a class="jxr_linenumber" name="50" href="#50">50</a>  <strong class="jxr_keyword">import</strong> org.junit.After;
<a class="jxr_linenumber" name="51" href="#51">51</a>  <strong class="jxr_keyword">import</strong> org.junit.AfterClass;
<a class="jxr_linenumber" name="52" href="#52">52</a>  <strong class="jxr_keyword">import</strong> org.junit.BeforeClass;
<a class="jxr_linenumber" name="53" href="#53">53</a>  <strong class="jxr_keyword">import</strong> org.junit.Test;
<a class="jxr_linenumber" name="54" href="#54">54</a>  <strong class="jxr_keyword">import</strong> org.junit.experimental.categories.Category;
<a class="jxr_linenumber" name="55" href="#55">55</a>  
<a class="jxr_linenumber" name="56" href="#56">56</a>  <strong class="jxr_keyword">import</strong> com.google.common.collect.Lists;
<a class="jxr_linenumber" name="57" href="#57">57</a>  
<a class="jxr_linenumber" name="58" href="#58">58</a>  @Category(MediumTests.<strong class="jxr_keyword">class</strong>)
<a class="jxr_linenumber" name="59" href="#59">59</a>  <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">class</strong> <a href="../../../../../../org/apache/hadoop/hbase/zookeeper/lock/TestZKInterProcessReadWriteLock.html">TestZKInterProcessReadWriteLock</a> {
<a class="jxr_linenumber" name="60" href="#60">60</a>  
<a class="jxr_linenumber" name="61" href="#61">61</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">final</strong> Log LOG =
<a class="jxr_linenumber" name="62" href="#62">62</a>        LogFactory.getLog(TestZKInterProcessReadWriteLock.<strong class="jxr_keyword">class</strong>);
<a class="jxr_linenumber" name="63" href="#63">63</a>  
<a class="jxr_linenumber" name="64" href="#64">64</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">final</strong> <a href="../../../../../../org/apache/hadoop/hbase/HBaseTestingUtility.html">HBaseTestingUtility</a> TEST_UTIL =
<a class="jxr_linenumber" name="65" href="#65">65</a>        <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/HBaseTestingUtility.html">HBaseTestingUtility</a>();
<a class="jxr_linenumber" name="66" href="#66">66</a>  
<a class="jxr_linenumber" name="67" href="#67">67</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">final</strong> <strong class="jxr_keyword">int</strong> NUM_THREADS = 10;
<a class="jxr_linenumber" name="68" href="#68">68</a>  
<a class="jxr_linenumber" name="69" href="#69">69</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> Configuration conf;
<a class="jxr_linenumber" name="70" href="#70">70</a>  
<a class="jxr_linenumber" name="71" href="#71">71</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">final</strong> AtomicBoolean isLockHeld = <strong class="jxr_keyword">new</strong> AtomicBoolean(false);
<a class="jxr_linenumber" name="72" href="#72">72</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">final</strong> ExecutorService executor =
<a class="jxr_linenumber" name="73" href="#73">73</a>        Executors.newFixedThreadPool(NUM_THREADS,
<a class="jxr_linenumber" name="74" href="#74">74</a>            <strong class="jxr_keyword">new</strong> DaemonThreadFactory(<span class="jxr_string">"TestZKInterProcessReadWriteLock-"</span>));
<a class="jxr_linenumber" name="75" href="#75">75</a>  
<a class="jxr_linenumber" name="76" href="#76">76</a>    @BeforeClass
<a class="jxr_linenumber" name="77" href="#77">77</a>    <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">void</strong> beforeAllTests() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="78" href="#78">78</a>      conf = TEST_UTIL.getConfiguration();
<a class="jxr_linenumber" name="79" href="#79">79</a>      TEST_UTIL.startMiniZKCluster();
<a class="jxr_linenumber" name="80" href="#80">80</a>      conf.setInt(HConstants.ZK_SESSION_TIMEOUT, 1000);
<a class="jxr_linenumber" name="81" href="#81">81</a>      ZooKeeperWatcher zkw = getZooKeeperWatcher(<span class="jxr_string">"setup"</span>);
<a class="jxr_linenumber" name="82" href="#82">82</a>      ZKUtil.createWithParents(zkw, zkw.tableLockZNode);
<a class="jxr_linenumber" name="83" href="#83">83</a>    }
<a class="jxr_linenumber" name="84" href="#84">84</a>  
<a class="jxr_linenumber" name="85" href="#85">85</a>    @AfterClass
<a class="jxr_linenumber" name="86" href="#86">86</a>    <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">void</strong> afterAllTests() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="87" href="#87">87</a>      TEST_UTIL.shutdownMiniZKCluster();
<a class="jxr_linenumber" name="88" href="#88">88</a>    }
<a class="jxr_linenumber" name="89" href="#89">89</a>  
<a class="jxr_linenumber" name="90" href="#90">90</a>    @After
<a class="jxr_linenumber" name="91" href="#91">91</a>    <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> tearDown() {
<a class="jxr_linenumber" name="92" href="#92">92</a>      executor.shutdown();
<a class="jxr_linenumber" name="93" href="#93">93</a>    }
<a class="jxr_linenumber" name="94" href="#94">94</a>  
<a class="jxr_linenumber" name="95" href="#95">95</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> ZooKeeperWatcher getZooKeeperWatcher(String desc)
<a class="jxr_linenumber" name="96" href="#96">96</a>    <strong class="jxr_keyword">throws</strong> IOException {
<a class="jxr_linenumber" name="97" href="#97">97</a>      <strong class="jxr_keyword">return</strong> TEST_UTIL.getZooKeeperWatcher();
<a class="jxr_linenumber" name="98" href="#98">98</a>    }
<a class="jxr_linenumber" name="99" href="#99">99</a>  
<a class="jxr_linenumber" name="100" href="#100">100</a> 
<a class="jxr_linenumber" name="101" href="#101">101</a>   @Test(timeout = 30000)
<a class="jxr_linenumber" name="102" href="#102">102</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> testWriteLockExcludesWriters() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="103" href="#103">103</a>     <strong class="jxr_keyword">final</strong> String testName = <span class="jxr_string">"testWriteLockExcludesWriters"</span>;
<a class="jxr_linenumber" name="104" href="#104">104</a>     <strong class="jxr_keyword">final</strong> ZKInterProcessReadWriteLock readWriteLock =
<a class="jxr_linenumber" name="105" href="#105">105</a>         getReadWriteLock(testName);
<a class="jxr_linenumber" name="106" href="#106">106</a>     List&lt;Future&lt;Void&gt;&gt; results = Lists.newArrayList();
<a class="jxr_linenumber" name="107" href="#107">107</a>     <strong class="jxr_keyword">for</strong> (<strong class="jxr_keyword">int</strong> i = 0; i &lt; NUM_THREADS; ++i) {
<a class="jxr_linenumber" name="108" href="#108">108</a>       <strong class="jxr_keyword">final</strong> String threadDesc = testName + i;
<a class="jxr_linenumber" name="109" href="#109">109</a>       results.add(executor.submit(<strong class="jxr_keyword">new</strong> Callable&lt;Void&gt;() {
<a class="jxr_linenumber" name="110" href="#110">110</a>         @Override
<a class="jxr_linenumber" name="111" href="#111">111</a>         <strong class="jxr_keyword">public</strong> Void call() <strong class="jxr_keyword">throws</strong> IOException {
<a class="jxr_linenumber" name="112" href="#112">112</a>           ZKInterProcessWriteLock writeLock =
<a class="jxr_linenumber" name="113" href="#113">113</a>               readWriteLock.writeLock(Bytes.toBytes(threadDesc));
<a class="jxr_linenumber" name="114" href="#114">114</a>           <strong class="jxr_keyword">try</strong> {
<a class="jxr_linenumber" name="115" href="#115">115</a>             writeLock.acquire();
<a class="jxr_linenumber" name="116" href="#116">116</a>             <strong class="jxr_keyword">try</strong> {
<a class="jxr_linenumber" name="117" href="#117">117</a>               <em class="jxr_comment">// No one else should hold the lock</em>
<a class="jxr_linenumber" name="118" href="#118">118</a>               assertTrue(isLockHeld.compareAndSet(false, <strong class="jxr_keyword">true</strong>));
<a class="jxr_linenumber" name="119" href="#119">119</a>               Thread.sleep(1000);
<a class="jxr_linenumber" name="120" href="#120">120</a>               <em class="jxr_comment">// No one else should have released the lock</em>
<a class="jxr_linenumber" name="121" href="#121">121</a>               assertTrue(isLockHeld.compareAndSet(<strong class="jxr_keyword">true</strong>, false));
<a class="jxr_linenumber" name="122" href="#122">122</a>             } <strong class="jxr_keyword">finally</strong> {
<a class="jxr_linenumber" name="123" href="#123">123</a>               isLockHeld.set(false);
<a class="jxr_linenumber" name="124" href="#124">124</a>               writeLock.release();
<a class="jxr_linenumber" name="125" href="#125">125</a>             }
<a class="jxr_linenumber" name="126" href="#126">126</a>           } <strong class="jxr_keyword">catch</strong> (InterruptedException e) {
<a class="jxr_linenumber" name="127" href="#127">127</a>             LOG.warn(threadDesc + <span class="jxr_string">" interrupted"</span>, e);
<a class="jxr_linenumber" name="128" href="#128">128</a>             Thread.currentThread().interrupt();
<a class="jxr_linenumber" name="129" href="#129">129</a>             <strong class="jxr_keyword">throw</strong> <strong class="jxr_keyword">new</strong> InterruptedIOException();
<a class="jxr_linenumber" name="130" href="#130">130</a>           }
<a class="jxr_linenumber" name="131" href="#131">131</a>           <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="132" href="#132">132</a>         }
<a class="jxr_linenumber" name="133" href="#133">133</a>       }));
<a class="jxr_linenumber" name="134" href="#134">134</a> 
<a class="jxr_linenumber" name="135" href="#135">135</a>     }
<a class="jxr_linenumber" name="136" href="#136">136</a>     MultithreadedTestUtil.assertOnFutures(results);
<a class="jxr_linenumber" name="137" href="#137">137</a>   }
<a class="jxr_linenumber" name="138" href="#138">138</a> 
<a class="jxr_linenumber" name="139" href="#139">139</a>   @Test(timeout = 30000)
<a class="jxr_linenumber" name="140" href="#140">140</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> testReadLockDoesNotExcludeReaders() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="141" href="#141">141</a>     <strong class="jxr_keyword">final</strong> String testName = <span class="jxr_string">"testReadLockDoesNotExcludeReaders"</span>;
<a class="jxr_linenumber" name="142" href="#142">142</a>     <strong class="jxr_keyword">final</strong> ZKInterProcessReadWriteLock readWriteLock =
<a class="jxr_linenumber" name="143" href="#143">143</a>         getReadWriteLock(testName);
<a class="jxr_linenumber" name="144" href="#144">144</a>     <strong class="jxr_keyword">final</strong> CountDownLatch locksAcquiredLatch = <strong class="jxr_keyword">new</strong> CountDownLatch(NUM_THREADS);
<a class="jxr_linenumber" name="145" href="#145">145</a>     <strong class="jxr_keyword">final</strong> AtomicInteger locksHeld = <strong class="jxr_keyword">new</strong> AtomicInteger(0);
<a class="jxr_linenumber" name="146" href="#146">146</a>     List&lt;Future&lt;Void&gt;&gt; results = Lists.newArrayList();
<a class="jxr_linenumber" name="147" href="#147">147</a>     <strong class="jxr_keyword">for</strong> (<strong class="jxr_keyword">int</strong> i = 0; i &lt; NUM_THREADS; ++i) {
<a class="jxr_linenumber" name="148" href="#148">148</a>       <strong class="jxr_keyword">final</strong> String threadDesc = testName + i;
<a class="jxr_linenumber" name="149" href="#149">149</a>       results.add(executor.submit(<strong class="jxr_keyword">new</strong> Callable&lt;Void&gt;() {
<a class="jxr_linenumber" name="150" href="#150">150</a>         @Override
<a class="jxr_linenumber" name="151" href="#151">151</a>         <strong class="jxr_keyword">public</strong> Void call() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="152" href="#152">152</a>           ZKInterProcessReadLock readLock =
<a class="jxr_linenumber" name="153" href="#153">153</a>               readWriteLock.readLock(Bytes.toBytes(threadDesc));
<a class="jxr_linenumber" name="154" href="#154">154</a>           readLock.acquire();
<a class="jxr_linenumber" name="155" href="#155">155</a>           <strong class="jxr_keyword">try</strong> {
<a class="jxr_linenumber" name="156" href="#156">156</a>             locksHeld.incrementAndGet();
<a class="jxr_linenumber" name="157" href="#157">157</a>             locksAcquiredLatch.countDown();
<a class="jxr_linenumber" name="158" href="#158">158</a>             Thread.sleep(1000);
<a class="jxr_linenumber" name="159" href="#159">159</a>           } <strong class="jxr_keyword">finally</strong> {
<a class="jxr_linenumber" name="160" href="#160">160</a>             readLock.release();
<a class="jxr_linenumber" name="161" href="#161">161</a>             locksHeld.decrementAndGet();
<a class="jxr_linenumber" name="162" href="#162">162</a>           }
<a class="jxr_linenumber" name="163" href="#163">163</a>           <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="164" href="#164">164</a>         }
<a class="jxr_linenumber" name="165" href="#165">165</a>       }));
<a class="jxr_linenumber" name="166" href="#166">166</a>     }
<a class="jxr_linenumber" name="167" href="#167">167</a>     locksAcquiredLatch.await();
<a class="jxr_linenumber" name="168" href="#168">168</a>     assertEquals(locksHeld.get(), NUM_THREADS);
<a class="jxr_linenumber" name="169" href="#169">169</a>     MultithreadedTestUtil.assertOnFutures(results);
<a class="jxr_linenumber" name="170" href="#170">170</a>   }
<a class="jxr_linenumber" name="171" href="#171">171</a> 
<a class="jxr_linenumber" name="172" href="#172">172</a>   @Test(timeout = 30000)
<a class="jxr_linenumber" name="173" href="#173">173</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> testReadLockExcludesWriters() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="174" href="#174">174</a>     <em class="jxr_comment">// Submit a read lock request first</em>
<a class="jxr_linenumber" name="175" href="#175">175</a>     <em class="jxr_comment">// Submit a write lock request second</em>
<a class="jxr_linenumber" name="176" href="#176">176</a>     <strong class="jxr_keyword">final</strong> String testName = <span class="jxr_string">"testReadLockExcludesWriters"</span>;
<a class="jxr_linenumber" name="177" href="#177">177</a>     List&lt;Future&lt;Void&gt;&gt; results = Lists.newArrayList();
<a class="jxr_linenumber" name="178" href="#178">178</a>     <strong class="jxr_keyword">final</strong> CountDownLatch readLockAcquiredLatch = <strong class="jxr_keyword">new</strong> CountDownLatch(1);
<a class="jxr_linenumber" name="179" href="#179">179</a>     Callable&lt;Void&gt; acquireReadLock = <strong class="jxr_keyword">new</strong> Callable&lt;Void&gt;() {
<a class="jxr_linenumber" name="180" href="#180">180</a>       @Override
<a class="jxr_linenumber" name="181" href="#181">181</a>       <strong class="jxr_keyword">public</strong> Void call() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="182" href="#182">182</a>         <strong class="jxr_keyword">final</strong> String threadDesc = testName + <span class="jxr_string">"-acquireReadLock"</span>;
<a class="jxr_linenumber" name="183" href="#183">183</a>         ZKInterProcessReadLock readLock =
<a class="jxr_linenumber" name="184" href="#184">184</a>             getReadWriteLock(testName).readLock(Bytes.toBytes(threadDesc));
<a class="jxr_linenumber" name="185" href="#185">185</a>         readLock.acquire();
<a class="jxr_linenumber" name="186" href="#186">186</a>         <strong class="jxr_keyword">try</strong> {
<a class="jxr_linenumber" name="187" href="#187">187</a>           assertTrue(isLockHeld.compareAndSet(false, <strong class="jxr_keyword">true</strong>));
<a class="jxr_linenumber" name="188" href="#188">188</a>           readLockAcquiredLatch.countDown();
<a class="jxr_linenumber" name="189" href="#189">189</a>           Thread.sleep(1000);
<a class="jxr_linenumber" name="190" href="#190">190</a>         } <strong class="jxr_keyword">finally</strong> {
<a class="jxr_linenumber" name="191" href="#191">191</a>           isLockHeld.set(false);
<a class="jxr_linenumber" name="192" href="#192">192</a>           readLock.release();
<a class="jxr_linenumber" name="193" href="#193">193</a>         }
<a class="jxr_linenumber" name="194" href="#194">194</a>         <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="195" href="#195">195</a>       }
<a class="jxr_linenumber" name="196" href="#196">196</a>     };
<a class="jxr_linenumber" name="197" href="#197">197</a>     Callable&lt;Void&gt; acquireWriteLock = <strong class="jxr_keyword">new</strong> Callable&lt;Void&gt;() {
<a class="jxr_linenumber" name="198" href="#198">198</a>       @Override
<a class="jxr_linenumber" name="199" href="#199">199</a>       <strong class="jxr_keyword">public</strong> Void call() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="200" href="#200">200</a>         <strong class="jxr_keyword">final</strong> String threadDesc = testName + <span class="jxr_string">"-acquireWriteLock"</span>;
<a class="jxr_linenumber" name="201" href="#201">201</a>         ZKInterProcessWriteLock writeLock =
<a class="jxr_linenumber" name="202" href="#202">202</a>             getReadWriteLock(testName).writeLock(Bytes.toBytes(threadDesc));
<a class="jxr_linenumber" name="203" href="#203">203</a>         readLockAcquiredLatch.await();
<a class="jxr_linenumber" name="204" href="#204">204</a>         assertTrue(isLockHeld.get());
<a class="jxr_linenumber" name="205" href="#205">205</a>         writeLock.acquire();
<a class="jxr_linenumber" name="206" href="#206">206</a>         <strong class="jxr_keyword">try</strong> {
<a class="jxr_linenumber" name="207" href="#207">207</a>           assertFalse(isLockHeld.get());
<a class="jxr_linenumber" name="208" href="#208">208</a>         } <strong class="jxr_keyword">finally</strong> {
<a class="jxr_linenumber" name="209" href="#209">209</a>           writeLock.release();
<a class="jxr_linenumber" name="210" href="#210">210</a>         }
<a class="jxr_linenumber" name="211" href="#211">211</a>         <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="212" href="#212">212</a>       }
<a class="jxr_linenumber" name="213" href="#213">213</a>     };
<a class="jxr_linenumber" name="214" href="#214">214</a>     results.add(executor.submit(acquireReadLock));
<a class="jxr_linenumber" name="215" href="#215">215</a>     results.add(executor.submit(acquireWriteLock));
<a class="jxr_linenumber" name="216" href="#216">216</a>     MultithreadedTestUtil.assertOnFutures(results);
<a class="jxr_linenumber" name="217" href="#217">217</a>   }
<a class="jxr_linenumber" name="218" href="#218">218</a> 
<a class="jxr_linenumber" name="219" href="#219">219</a>   <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> ZKInterProcessReadWriteLock getReadWriteLock(String testName)
<a class="jxr_linenumber" name="220" href="#220">220</a>       <strong class="jxr_keyword">throws</strong> IOException {
<a class="jxr_linenumber" name="221" href="#221">221</a>     MetadataHandler handler = <strong class="jxr_keyword">new</strong> MetadataHandler() {
<a class="jxr_linenumber" name="222" href="#222">222</a>       @Override
<a class="jxr_linenumber" name="223" href="#223">223</a>       <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> handleMetadata(byte[] ownerMetadata) {
<a class="jxr_linenumber" name="224" href="#224">224</a>         LOG.info(<span class="jxr_string">"Lock info: "</span> + Bytes.toString(ownerMetadata));
<a class="jxr_linenumber" name="225" href="#225">225</a>       }
<a class="jxr_linenumber" name="226" href="#226">226</a>     };
<a class="jxr_linenumber" name="227" href="#227">227</a>     ZooKeeperWatcher zkWatcher = getZooKeeperWatcher(testName);
<a class="jxr_linenumber" name="228" href="#228">228</a>     String znode = ZKUtil.joinZNode(zkWatcher.tableLockZNode, testName);
<a class="jxr_linenumber" name="229" href="#229">229</a> 
<a class="jxr_linenumber" name="230" href="#230">230</a>     <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">new</strong> ZKInterProcessReadWriteLock(zkWatcher, znode, handler);
<a class="jxr_linenumber" name="231" href="#231">231</a>   }
<a class="jxr_linenumber" name="232" href="#232">232</a> 
<a class="jxr_linenumber" name="233" href="#233">233</a>   @Test(timeout = 30000)
<a class="jxr_linenumber" name="234" href="#234">234</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> testWriteLockExcludesReaders() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="235" href="#235">235</a>     <em class="jxr_comment">// Submit a read lock request first</em>
<a class="jxr_linenumber" name="236" href="#236">236</a>     <em class="jxr_comment">// Submit a write lock request second</em>
<a class="jxr_linenumber" name="237" href="#237">237</a>     <strong class="jxr_keyword">final</strong> String testName = <span class="jxr_string">"testReadLockExcludesWriters"</span>;
<a class="jxr_linenumber" name="238" href="#238">238</a>     List&lt;Future&lt;Void&gt;&gt; results = Lists.newArrayList();
<a class="jxr_linenumber" name="239" href="#239">239</a>     <strong class="jxr_keyword">final</strong> CountDownLatch writeLockAcquiredLatch = <strong class="jxr_keyword">new</strong> CountDownLatch(1);
<a class="jxr_linenumber" name="240" href="#240">240</a>     Callable&lt;Void&gt; acquireWriteLock = <strong class="jxr_keyword">new</strong> Callable&lt;Void&gt;() {
<a class="jxr_linenumber" name="241" href="#241">241</a>       @Override
<a class="jxr_linenumber" name="242" href="#242">242</a>       <strong class="jxr_keyword">public</strong> Void call() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="243" href="#243">243</a>         <strong class="jxr_keyword">final</strong> String threadDesc = testName + <span class="jxr_string">"-acquireWriteLock"</span>;
<a class="jxr_linenumber" name="244" href="#244">244</a>         ZKInterProcessWriteLock writeLock =
<a class="jxr_linenumber" name="245" href="#245">245</a>             getReadWriteLock(testName).writeLock(Bytes.toBytes(threadDesc));
<a class="jxr_linenumber" name="246" href="#246">246</a>         writeLock.acquire();
<a class="jxr_linenumber" name="247" href="#247">247</a>         <strong class="jxr_keyword">try</strong> {
<a class="jxr_linenumber" name="248" href="#248">248</a>           writeLockAcquiredLatch.countDown();
<a class="jxr_linenumber" name="249" href="#249">249</a>           assertTrue(isLockHeld.compareAndSet(false, <strong class="jxr_keyword">true</strong>));
<a class="jxr_linenumber" name="250" href="#250">250</a>           Thread.sleep(1000);
<a class="jxr_linenumber" name="251" href="#251">251</a>         } <strong class="jxr_keyword">finally</strong> {
<a class="jxr_linenumber" name="252" href="#252">252</a>           isLockHeld.set(false);
<a class="jxr_linenumber" name="253" href="#253">253</a>           writeLock.release();
<a class="jxr_linenumber" name="254" href="#254">254</a>         }
<a class="jxr_linenumber" name="255" href="#255">255</a>         <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="256" href="#256">256</a>       }
<a class="jxr_linenumber" name="257" href="#257">257</a>     };
<a class="jxr_linenumber" name="258" href="#258">258</a>     Callable&lt;Void&gt; acquireReadLock = <strong class="jxr_keyword">new</strong> Callable&lt;Void&gt;() {
<a class="jxr_linenumber" name="259" href="#259">259</a>       @Override
<a class="jxr_linenumber" name="260" href="#260">260</a>       <strong class="jxr_keyword">public</strong> Void call() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="261" href="#261">261</a>         <strong class="jxr_keyword">final</strong> String threadDesc = testName + <span class="jxr_string">"-acquireReadLock"</span>;
<a class="jxr_linenumber" name="262" href="#262">262</a>         ZKInterProcessReadLock readLock =
<a class="jxr_linenumber" name="263" href="#263">263</a>             getReadWriteLock(testName).readLock(Bytes.toBytes(threadDesc));
<a class="jxr_linenumber" name="264" href="#264">264</a>         writeLockAcquiredLatch.await();
<a class="jxr_linenumber" name="265" href="#265">265</a>         readLock.acquire();
<a class="jxr_linenumber" name="266" href="#266">266</a>         <strong class="jxr_keyword">try</strong> {
<a class="jxr_linenumber" name="267" href="#267">267</a>           assertFalse(isLockHeld.get());
<a class="jxr_linenumber" name="268" href="#268">268</a>         } <strong class="jxr_keyword">finally</strong> {
<a class="jxr_linenumber" name="269" href="#269">269</a>           readLock.release();
<a class="jxr_linenumber" name="270" href="#270">270</a>         }
<a class="jxr_linenumber" name="271" href="#271">271</a>         <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="272" href="#272">272</a>       }
<a class="jxr_linenumber" name="273" href="#273">273</a>     };
<a class="jxr_linenumber" name="274" href="#274">274</a>     results.add(executor.submit(acquireWriteLock));
<a class="jxr_linenumber" name="275" href="#275">275</a>     results.add(executor.submit(acquireReadLock));
<a class="jxr_linenumber" name="276" href="#276">276</a>     MultithreadedTestUtil.assertOnFutures(results);
<a class="jxr_linenumber" name="277" href="#277">277</a>   }
<a class="jxr_linenumber" name="278" href="#278">278</a> 
<a class="jxr_linenumber" name="279" href="#279">279</a>   @Test(timeout = 60000)
<a class="jxr_linenumber" name="280" href="#280">280</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> testTimeout() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="281" href="#281">281</a>     <strong class="jxr_keyword">final</strong> String testName = <span class="jxr_string">"testTimeout"</span>;
<a class="jxr_linenumber" name="282" href="#282">282</a>     <strong class="jxr_keyword">final</strong> CountDownLatch lockAcquiredLatch = <strong class="jxr_keyword">new</strong> CountDownLatch(1);
<a class="jxr_linenumber" name="283" href="#283">283</a>     Callable&lt;Void&gt; shouldHog = <strong class="jxr_keyword">new</strong> Callable&lt;Void&gt;() {
<a class="jxr_linenumber" name="284" href="#284">284</a>       @Override
<a class="jxr_linenumber" name="285" href="#285">285</a>       <strong class="jxr_keyword">public</strong> Void call() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="286" href="#286">286</a>         <strong class="jxr_keyword">final</strong> String threadDesc = testName + <span class="jxr_string">"-shouldHog"</span>;
<a class="jxr_linenumber" name="287" href="#287">287</a>         ZKInterProcessWriteLock lock =
<a class="jxr_linenumber" name="288" href="#288">288</a>             getReadWriteLock(testName).writeLock(Bytes.toBytes(threadDesc));
<a class="jxr_linenumber" name="289" href="#289">289</a>         lock.acquire();
<a class="jxr_linenumber" name="290" href="#290">290</a>         lockAcquiredLatch.countDown();
<a class="jxr_linenumber" name="291" href="#291">291</a>         Thread.sleep(10000);
<a class="jxr_linenumber" name="292" href="#292">292</a>         lock.release();
<a class="jxr_linenumber" name="293" href="#293">293</a>         <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="294" href="#294">294</a>       }
<a class="jxr_linenumber" name="295" href="#295">295</a>     };
<a class="jxr_linenumber" name="296" href="#296">296</a>     Callable&lt;Void&gt; shouldTimeout = <strong class="jxr_keyword">new</strong> Callable&lt;Void&gt;() {
<a class="jxr_linenumber" name="297" href="#297">297</a>       @Override
<a class="jxr_linenumber" name="298" href="#298">298</a>       <strong class="jxr_keyword">public</strong> Void call() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="299" href="#299">299</a>         <strong class="jxr_keyword">final</strong> String threadDesc = testName + <span class="jxr_string">"-shouldTimeout"</span>;
<a class="jxr_linenumber" name="300" href="#300">300</a>         ZKInterProcessWriteLock lock =
<a class="jxr_linenumber" name="301" href="#301">301</a>             getReadWriteLock(testName).writeLock(Bytes.toBytes(threadDesc));
<a class="jxr_linenumber" name="302" href="#302">302</a>         lockAcquiredLatch.await();
<a class="jxr_linenumber" name="303" href="#303">303</a>         assertFalse(lock.tryAcquire(5000));
<a class="jxr_linenumber" name="304" href="#304">304</a>         <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="305" href="#305">305</a>       }
<a class="jxr_linenumber" name="306" href="#306">306</a>     };
<a class="jxr_linenumber" name="307" href="#307">307</a>     Callable&lt;Void&gt; shouldAcquireLock = <strong class="jxr_keyword">new</strong> Callable&lt;Void&gt;() {
<a class="jxr_linenumber" name="308" href="#308">308</a>       @Override
<a class="jxr_linenumber" name="309" href="#309">309</a>       <strong class="jxr_keyword">public</strong> Void call() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="310" href="#310">310</a>         <strong class="jxr_keyword">final</strong> String threadDesc = testName + <span class="jxr_string">"-shouldAcquireLock"</span>;
<a class="jxr_linenumber" name="311" href="#311">311</a>         ZKInterProcessWriteLock lock =
<a class="jxr_linenumber" name="312" href="#312">312</a>             getReadWriteLock(testName).writeLock(Bytes.toBytes(threadDesc));
<a class="jxr_linenumber" name="313" href="#313">313</a>         lockAcquiredLatch.await();
<a class="jxr_linenumber" name="314" href="#314">314</a>         assertTrue(lock.tryAcquire(30000));
<a class="jxr_linenumber" name="315" href="#315">315</a>         lock.release();
<a class="jxr_linenumber" name="316" href="#316">316</a>         <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="317" href="#317">317</a>       }
<a class="jxr_linenumber" name="318" href="#318">318</a>     };
<a class="jxr_linenumber" name="319" href="#319">319</a>     List&lt;Future&lt;Void&gt;&gt; results = Lists.newArrayList();
<a class="jxr_linenumber" name="320" href="#320">320</a>     results.add(executor.submit(shouldHog));
<a class="jxr_linenumber" name="321" href="#321">321</a>     results.add(executor.submit(shouldTimeout));
<a class="jxr_linenumber" name="322" href="#322">322</a>     results.add(executor.submit(shouldAcquireLock));
<a class="jxr_linenumber" name="323" href="#323">323</a>     MultithreadedTestUtil.assertOnFutures(results);
<a class="jxr_linenumber" name="324" href="#324">324</a>   }
<a class="jxr_linenumber" name="325" href="#325">325</a> 
<a class="jxr_linenumber" name="326" href="#326">326</a>   @Test(timeout = 60000)
<a class="jxr_linenumber" name="327" href="#327">327</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> testMultipleClients() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="328" href="#328">328</a>     <em class="jxr_comment">//tests lock usage from multiple zookeeper clients with different sessions.</em>
<a class="jxr_linenumber" name="329" href="#329">329</a>     <em class="jxr_comment">//acquire one read lock, then one write lock</em>
<a class="jxr_linenumber" name="330" href="#330">330</a>     <strong class="jxr_keyword">final</strong> String testName = <span class="jxr_string">"testMultipleClients"</span>;
<a class="jxr_linenumber" name="331" href="#331">331</a> 
<a class="jxr_linenumber" name="332" href="#332">332</a>     <em class="jxr_comment">//different zookeeper sessions with separate identifiers</em>
<a class="jxr_linenumber" name="333" href="#333">333</a>     ZooKeeperWatcher zkWatcher1 = <strong class="jxr_keyword">new</strong> ZooKeeperWatcher(conf, <span class="jxr_string">"testMultipleClients-1"</span>, <strong class="jxr_keyword">null</strong>);
<a class="jxr_linenumber" name="334" href="#334">334</a>     ZooKeeperWatcher zkWatcher2 = <strong class="jxr_keyword">new</strong> ZooKeeperWatcher(conf, <span class="jxr_string">"testMultipleClients-2"</span>, <strong class="jxr_keyword">null</strong>);
<a class="jxr_linenumber" name="335" href="#335">335</a> 
<a class="jxr_linenumber" name="336" href="#336">336</a>     String znode = ZKUtil.joinZNode(zkWatcher1.tableLockZNode, testName);
<a class="jxr_linenumber" name="337" href="#337">337</a> 
<a class="jxr_linenumber" name="338" href="#338">338</a>     ZKInterProcessReadWriteLock clientLock1
<a class="jxr_linenumber" name="339" href="#339">339</a>       = <strong class="jxr_keyword">new</strong> ZKInterProcessReadWriteLock(zkWatcher1, znode, <strong class="jxr_keyword">null</strong>);
<a class="jxr_linenumber" name="340" href="#340">340</a>     ZKInterProcessReadWriteLock clientLock2
<a class="jxr_linenumber" name="341" href="#341">341</a>       = <strong class="jxr_keyword">new</strong> ZKInterProcessReadWriteLock(zkWatcher2, znode, <strong class="jxr_keyword">null</strong>);
<a class="jxr_linenumber" name="342" href="#342">342</a> 
<a class="jxr_linenumber" name="343" href="#343">343</a>     InterProcessLock lock1 = clientLock1.readLock(Bytes.toBytes(<span class="jxr_string">"client1"</span>));
<a class="jxr_linenumber" name="344" href="#344">344</a>     lock1.acquire();
<a class="jxr_linenumber" name="345" href="#345">345</a> 
<a class="jxr_linenumber" name="346" href="#346">346</a>     <em class="jxr_comment">//try to acquire, but it will timeout. We are testing whether this will cause any problems</em>
<a class="jxr_linenumber" name="347" href="#347">347</a>     <em class="jxr_comment">//due to the read lock being from another client</em>
<a class="jxr_linenumber" name="348" href="#348">348</a>     InterProcessLock lock2 = clientLock2.writeLock(Bytes.toBytes(<span class="jxr_string">"client2"</span>));
<a class="jxr_linenumber" name="349" href="#349">349</a>     assertFalse(lock2.tryAcquire(1000));
<a class="jxr_linenumber" name="350" href="#350">350</a> 
<a class="jxr_linenumber" name="351" href="#351">351</a>     lock1.release();
<a class="jxr_linenumber" name="352" href="#352">352</a> 
<a class="jxr_linenumber" name="353" href="#353">353</a>     <em class="jxr_comment">//this time it will acquire</em>
<a class="jxr_linenumber" name="354" href="#354">354</a>     assertTrue(lock2.tryAcquire(5000));
<a class="jxr_linenumber" name="355" href="#355">355</a>     lock2.release();
<a class="jxr_linenumber" name="356" href="#356">356</a>     zkWatcher1.close();
<a class="jxr_linenumber" name="357" href="#357">357</a>     zkWatcher2.close();
<a class="jxr_linenumber" name="358" href="#358">358</a>   }
<a class="jxr_linenumber" name="359" href="#359">359</a> }
</pre>
<hr/><div id="footer">This page was automatically generated by <a href="http://maven.apache.org/">Maven</a></div></body>
</html>

