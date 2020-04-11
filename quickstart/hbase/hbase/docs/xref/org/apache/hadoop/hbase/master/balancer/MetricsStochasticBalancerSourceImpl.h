<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8" />
<title>MetricsStochasticBalancerSourceImpl xref</title>
<link type="text/css" rel="stylesheet" href="../../../../../../stylesheet.css" />
</head>
<body>
<div id="overview"><a href="../../../../../../../apidocs/org/apache/hadoop/hbase/master/balancer/MetricsStochasticBalancerSourceImpl.html">View Javadoc</a></div><pre>

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
<a class="jxr_linenumber" name="18" href="#18">18</a>  
<a class="jxr_linenumber" name="19" href="#19">19</a>  <strong class="jxr_keyword">package</strong> org.apache.hadoop.hbase.master.balancer;
<a class="jxr_linenumber" name="20" href="#20">20</a>  
<a class="jxr_linenumber" name="21" href="#21">21</a>  <strong class="jxr_keyword">import</strong> java.util.LinkedHashMap;
<a class="jxr_linenumber" name="22" href="#22">22</a>  <strong class="jxr_keyword">import</strong> java.util.Map;
<a class="jxr_linenumber" name="23" href="#23">23</a>  <strong class="jxr_keyword">import</strong> java.util.concurrent.ConcurrentHashMap;
<a class="jxr_linenumber" name="24" href="#24">24</a>  
<a class="jxr_linenumber" name="25" href="#25">25</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.classification.InterfaceAudience;
<a class="jxr_linenumber" name="26" href="#26">26</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.metrics.Interns;
<a class="jxr_linenumber" name="27" href="#27">27</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.metrics2.MetricsCollector;
<a class="jxr_linenumber" name="28" href="#28">28</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.metrics2.MetricsRecordBuilder;
<a class="jxr_linenumber" name="29" href="#29">29</a>  
<a class="jxr_linenumber" name="30" href="#30">30</a>  @InterfaceAudience.Private
<a class="jxr_linenumber" name="31" href="#31">31</a>  <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">class</strong> <a href="../../../../../../org/apache/hadoop/hbase/master/balancer/MetricsStochasticBalancerSourceImpl.html">MetricsStochasticBalancerSourceImpl</a> <strong class="jxr_keyword">extends</strong> <a href="../../../../../../org/apache/hadoop/hbase/master/balancer/MetricsBalancerSourceImpl.html">MetricsBalancerSourceImpl</a> <strong class="jxr_keyword">implements</strong>
<a class="jxr_linenumber" name="32" href="#32">32</a>      <a href="../../../../../../org/apache/hadoop/hbase/master/balancer/MetricsStochasticBalancerSource.html">MetricsStochasticBalancerSource</a> {
<a class="jxr_linenumber" name="33" href="#33">33</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">final</strong> String TABLE_FUNCTION_SEP = <span class="jxr_string">"_"</span>;
<a class="jxr_linenumber" name="34" href="#34">34</a>  
<a class="jxr_linenumber" name="35" href="#35">35</a>    <em class="jxr_comment">// Most Recently Used(MRU) cache</em>
<a class="jxr_linenumber" name="36" href="#36">36</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">final</strong> <strong class="jxr_keyword">float</strong> MRU_LOAD_FACTOR = 0.75f;
<a class="jxr_linenumber" name="37" href="#37">37</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">int</strong> metricsSize = 1000;
<a class="jxr_linenumber" name="38" href="#38">38</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">int</strong> mruCap = calcMruCap(metricsSize);
<a class="jxr_linenumber" name="39" href="#39">39</a>  
<a class="jxr_linenumber" name="40" href="#40">40</a>    <strong class="jxr_keyword">private</strong> Map&lt;String, Map&lt;String, Double&gt;&gt; stochasticCosts =
<a class="jxr_linenumber" name="41" href="#41">41</a>        <strong class="jxr_keyword">new</strong> LinkedHashMap&lt;String, Map&lt;String, Double&gt;&gt;(mruCap, MRU_LOAD_FACTOR, <strong class="jxr_keyword">true</strong>) {
<a class="jxr_linenumber" name="42" href="#42">42</a>          <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">final</strong> <strong class="jxr_keyword">long</strong> serialVersionUID = 8204713453436906599L;
<a class="jxr_linenumber" name="43" href="#43">43</a>  
<a class="jxr_linenumber" name="44" href="#44">44</a>          @Override
<a class="jxr_linenumber" name="45" href="#45">45</a>          <strong class="jxr_keyword">protected</strong> <strong class="jxr_keyword">boolean</strong> removeEldestEntry(Map.Entry&lt;String, Map&lt;String, Double&gt;&gt; eldest) {
<a class="jxr_linenumber" name="46" href="#46">46</a>            <strong class="jxr_keyword">return</strong> size() &gt; mruCap;
<a class="jxr_linenumber" name="47" href="#47">47</a>          }
<a class="jxr_linenumber" name="48" href="#48">48</a>        };
<a class="jxr_linenumber" name="49" href="#49">49</a>    <strong class="jxr_keyword">private</strong> Map&lt;String, String&gt; costFunctionDescs = <strong class="jxr_keyword">new</strong> ConcurrentHashMap&lt;String, String&gt;();
<a class="jxr_linenumber" name="50" href="#50">50</a>  
<a class="jxr_linenumber" name="51" href="#51">51</a>    <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="52" href="#52">52</a>  <em class="jxr_javadoccomment">   * Calculates the mru cache capacity from the metrics size</em>
<a class="jxr_linenumber" name="53" href="#53">53</a>  <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="54" href="#54">54</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">static</strong> <strong class="jxr_keyword">int</strong> calcMruCap(<strong class="jxr_keyword">int</strong> metricsSize) {
<a class="jxr_linenumber" name="55" href="#55">55</a>      <strong class="jxr_keyword">return</strong> (<strong class="jxr_keyword">int</strong>) Math.ceil(metricsSize / MRU_LOAD_FACTOR) + 1;
<a class="jxr_linenumber" name="56" href="#56">56</a>    }
<a class="jxr_linenumber" name="57" href="#57">57</a>  
<a class="jxr_linenumber" name="58" href="#58">58</a>    @Override
<a class="jxr_linenumber" name="59" href="#59">59</a>    <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> updateMetricsSize(<strong class="jxr_keyword">int</strong> size) {
<a class="jxr_linenumber" name="60" href="#60">60</a>      <strong class="jxr_keyword">if</strong> (size &gt; 0) {
<a class="jxr_linenumber" name="61" href="#61">61</a>        metricsSize = size;
<a class="jxr_linenumber" name="62" href="#62">62</a>        mruCap = calcMruCap(size);
<a class="jxr_linenumber" name="63" href="#63">63</a>      }
<a class="jxr_linenumber" name="64" href="#64">64</a>    }
<a class="jxr_linenumber" name="65" href="#65">65</a>  
<a class="jxr_linenumber" name="66" href="#66">66</a>    <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="67" href="#67">67</a>  <em class="jxr_javadoccomment">   * Reports stochastic load balancer costs to JMX</em>
<a class="jxr_linenumber" name="68" href="#68">68</a>  <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="69" href="#69">69</a>    <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> updateStochasticCost(String tableName, String costFunctionName, String functionDesc,
<a class="jxr_linenumber" name="70" href="#70">70</a>        Double cost) {
<a class="jxr_linenumber" name="71" href="#71">71</a>      <strong class="jxr_keyword">if</strong> (tableName == <strong class="jxr_keyword">null</strong> || costFunctionName == <strong class="jxr_keyword">null</strong> || cost == <strong class="jxr_keyword">null</strong>) {
<a class="jxr_linenumber" name="72" href="#72">72</a>        <strong class="jxr_keyword">return</strong>;
<a class="jxr_linenumber" name="73" href="#73">73</a>      }
<a class="jxr_linenumber" name="74" href="#74">74</a>  
<a class="jxr_linenumber" name="75" href="#75">75</a>      <strong class="jxr_keyword">if</strong> (functionDesc != <strong class="jxr_keyword">null</strong>) {
<a class="jxr_linenumber" name="76" href="#76">76</a>        costFunctionDescs.put(costFunctionName, functionDesc);
<a class="jxr_linenumber" name="77" href="#77">77</a>      }
<a class="jxr_linenumber" name="78" href="#78">78</a>  
<a class="jxr_linenumber" name="79" href="#79">79</a>      <strong class="jxr_keyword">synchronized</strong> (stochasticCosts) {
<a class="jxr_linenumber" name="80" href="#80">80</a>        Map&lt;String, Double&gt; costs = stochasticCosts.get(tableName);
<a class="jxr_linenumber" name="81" href="#81">81</a>        <strong class="jxr_keyword">if</strong> (costs == <strong class="jxr_keyword">null</strong>) {
<a class="jxr_linenumber" name="82" href="#82">82</a>          costs = <strong class="jxr_keyword">new</strong> ConcurrentHashMap&lt;String, Double&gt;();
<a class="jxr_linenumber" name="83" href="#83">83</a>        }
<a class="jxr_linenumber" name="84" href="#84">84</a>  
<a class="jxr_linenumber" name="85" href="#85">85</a>        costs.put(costFunctionName, cost);
<a class="jxr_linenumber" name="86" href="#86">86</a>        stochasticCosts.put(tableName, costs);
<a class="jxr_linenumber" name="87" href="#87">87</a>      }
<a class="jxr_linenumber" name="88" href="#88">88</a>    }
<a class="jxr_linenumber" name="89" href="#89">89</a>  
<a class="jxr_linenumber" name="90" href="#90">90</a>    @Override
<a class="jxr_linenumber" name="91" href="#91">91</a>    <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> getMetrics(MetricsCollector metricsCollector, <strong class="jxr_keyword">boolean</strong> all) {
<a class="jxr_linenumber" name="92" href="#92">92</a>      MetricsRecordBuilder metricsRecordBuilder = metricsCollector.addRecord(metricsName);
<a class="jxr_linenumber" name="93" href="#93">93</a>  
<a class="jxr_linenumber" name="94" href="#94">94</a>      <strong class="jxr_keyword">if</strong> (stochasticCosts != <strong class="jxr_keyword">null</strong>) {
<a class="jxr_linenumber" name="95" href="#95">95</a>        <strong class="jxr_keyword">synchronized</strong> (stochasticCosts) {
<a class="jxr_linenumber" name="96" href="#96">96</a>          <strong class="jxr_keyword">for</strong> (Map.Entry&lt;String, Map&lt;String, Double&gt;&gt; tableEntry : stochasticCosts.entrySet()) {
<a class="jxr_linenumber" name="97" href="#97">97</a>            <strong class="jxr_keyword">for</strong> (Map.Entry&lt;String, Double&gt; costEntry : tableEntry.getValue().entrySet()) {
<a class="jxr_linenumber" name="98" href="#98">98</a>              String attrName = tableEntry.getKey() + TABLE_FUNCTION_SEP + costEntry.getKey();
<a class="jxr_linenumber" name="99" href="#99">99</a>              Double cost = costEntry.getValue();
<a class="jxr_linenumber" name="100" href="#100">100</a>             String functionDesc = costFunctionDescs.get(costEntry.getKey());
<a class="jxr_linenumber" name="101" href="#101">101</a>             <strong class="jxr_keyword">if</strong> (functionDesc == <strong class="jxr_keyword">null</strong>) functionDesc = costEntry.getKey();
<a class="jxr_linenumber" name="102" href="#102">102</a>             metricsRecordBuilder.addGauge(Interns.info(attrName, functionDesc), cost);
<a class="jxr_linenumber" name="103" href="#103">103</a>           }
<a class="jxr_linenumber" name="104" href="#104">104</a>         }
<a class="jxr_linenumber" name="105" href="#105">105</a>       }
<a class="jxr_linenumber" name="106" href="#106">106</a>     }
<a class="jxr_linenumber" name="107" href="#107">107</a>     metricsRegistry.snapshot(metricsRecordBuilder, all);
<a class="jxr_linenumber" name="108" href="#108">108</a>   }
<a class="jxr_linenumber" name="109" href="#109">109</a> 
<a class="jxr_linenumber" name="110" href="#110">110</a> }
</pre>
<hr/><div id="footer">This page was automatically generated by <a href="http://maven.apache.org/">Maven</a></div></body>
</html>

