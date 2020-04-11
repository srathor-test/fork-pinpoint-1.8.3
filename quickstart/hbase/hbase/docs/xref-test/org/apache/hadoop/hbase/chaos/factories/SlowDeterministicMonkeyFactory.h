<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8" />
<title>SlowDeterministicMonkeyFactory xref</title>
<link type="text/css" rel="stylesheet" href="../../../../../../stylesheet.css" />
</head>
<body>
<div id="overview"><a href="../../../../../../../testapidocs/org/apache/hadoop/hbase/chaos/factories/SlowDeterministicMonkeyFactory.html">View Javadoc</a></div><pre>

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
<a class="jxr_linenumber" name="19" href="#19">19</a>  <strong class="jxr_keyword">package</strong> org.apache.hadoop.hbase.chaos.factories;
<a class="jxr_linenumber" name="20" href="#20">20</a>  
<a class="jxr_linenumber" name="21" href="#21">21</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.chaos.actions.*;
<a class="jxr_linenumber" name="22" href="#22">22</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.chaos.monkies.ChaosMonkey;
<a class="jxr_linenumber" name="23" href="#23">23</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.chaos.monkies.PolicyBasedChaosMonkey;
<a class="jxr_linenumber" name="24" href="#24">24</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.chaos.policies.CompositeSequentialPolicy;
<a class="jxr_linenumber" name="25" href="#25">25</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.chaos.policies.DoActionsOncePolicy;
<a class="jxr_linenumber" name="26" href="#26">26</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.chaos.policies.PeriodicRandomActionPolicy;
<a class="jxr_linenumber" name="27" href="#27">27</a>  
<a class="jxr_linenumber" name="28" href="#28">28</a>  <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">class</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/factories/SlowDeterministicMonkeyFactory.html">SlowDeterministicMonkeyFactory</a> <strong class="jxr_keyword">extends</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/factories/MonkeyFactory.html">MonkeyFactory</a> {
<a class="jxr_linenumber" name="29" href="#29">29</a>  
<a class="jxr_linenumber" name="30" href="#30">30</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> action1Period;
<a class="jxr_linenumber" name="31" href="#31">31</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> action2Period;
<a class="jxr_linenumber" name="32" href="#32">32</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> action3Period;
<a class="jxr_linenumber" name="33" href="#33">33</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> action4Period;
<a class="jxr_linenumber" name="34" href="#34">34</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> moveRegionsMaxTime;
<a class="jxr_linenumber" name="35" href="#35">35</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> moveRegionsSleepTime;
<a class="jxr_linenumber" name="36" href="#36">36</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> moveRandomRegionSleepTime;
<a class="jxr_linenumber" name="37" href="#37">37</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> restartRandomRSSleepTime;
<a class="jxr_linenumber" name="38" href="#38">38</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> batchRestartRSSleepTime;
<a class="jxr_linenumber" name="39" href="#39">39</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">float</strong> batchRestartRSRatio;
<a class="jxr_linenumber" name="40" href="#40">40</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> restartActiveMasterSleepTime;
<a class="jxr_linenumber" name="41" href="#41">41</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> rollingBatchRestartRSSleepTime;
<a class="jxr_linenumber" name="42" href="#42">42</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">float</strong> rollingBatchRestartRSRatio;
<a class="jxr_linenumber" name="43" href="#43">43</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> restartRsHoldingMetaSleepTime;
<a class="jxr_linenumber" name="44" href="#44">44</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">float</strong> compactTableRatio;
<a class="jxr_linenumber" name="45" href="#45">45</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">float</strong> compactRandomRegionRatio;
<a class="jxr_linenumber" name="46" href="#46">46</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> decreaseHFileSizeSleepTime;
<a class="jxr_linenumber" name="47" href="#47">47</a>  
<a class="jxr_linenumber" name="48" href="#48">48</a>    @Override
<a class="jxr_linenumber" name="49" href="#49">49</a>    <strong class="jxr_keyword">public</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/monkies/ChaosMonkey.html">ChaosMonkey</a> build() {
<a class="jxr_linenumber" name="50" href="#50">50</a>  
<a class="jxr_linenumber" name="51" href="#51">51</a>      loadProperties();
<a class="jxr_linenumber" name="52" href="#52">52</a>      <em class="jxr_comment">// Actions such as compact/flush a table/region,</em>
<a class="jxr_linenumber" name="53" href="#53">53</a>      <em class="jxr_comment">// move one region around. They are not so destructive,</em>
<a class="jxr_linenumber" name="54" href="#54">54</a>      <em class="jxr_comment">// can be executed more frequently.</em>
<a class="jxr_linenumber" name="55" href="#55">55</a>      <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/Action.html">Action</a>[] actions1 = <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/Action.html">Action</a>[] {
<a class="jxr_linenumber" name="56" href="#56">56</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/CompactTableAction.html">CompactTableAction</a>(tableName, compactTableRatio),
<a class="jxr_linenumber" name="57" href="#57">57</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/CompactRandomRegionOfTableAction.html">CompactRandomRegionOfTableAction</a>(tableName, compactRandomRegionRatio),
<a class="jxr_linenumber" name="58" href="#58">58</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/FlushTableAction.html">FlushTableAction</a>(tableName),
<a class="jxr_linenumber" name="59" href="#59">59</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/FlushRandomRegionOfTableAction.html">FlushRandomRegionOfTableAction</a>(tableName),
<a class="jxr_linenumber" name="60" href="#60">60</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/MoveRandomRegionOfTableAction.html">MoveRandomRegionOfTableAction</a>(tableName)
<a class="jxr_linenumber" name="61" href="#61">61</a>      };
<a class="jxr_linenumber" name="62" href="#62">62</a>  
<a class="jxr_linenumber" name="63" href="#63">63</a>      <em class="jxr_comment">// Actions such as split/merge/snapshot.</em>
<a class="jxr_linenumber" name="64" href="#64">64</a>      <em class="jxr_comment">// They should not cause data loss, or unreliability</em>
<a class="jxr_linenumber" name="65" href="#65">65</a>      <em class="jxr_comment">// such as region stuck in transition.</em>
<a class="jxr_linenumber" name="66" href="#66">66</a>      <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/Action.html">Action</a>[] actions2 = <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/Action.html">Action</a>[] {
<a class="jxr_linenumber" name="67" href="#67">67</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/SplitRandomRegionOfTableAction.html">SplitRandomRegionOfTableAction</a>(tableName),
<a class="jxr_linenumber" name="68" href="#68">68</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/MergeRandomAdjacentRegionsOfTableAction.html">MergeRandomAdjacentRegionsOfTableAction</a>(tableName),
<a class="jxr_linenumber" name="69" href="#69">69</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/SnapshotTableAction.html">SnapshotTableAction</a>(tableName),
<a class="jxr_linenumber" name="70" href="#70">70</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/AddColumnAction.html">AddColumnAction</a>(tableName),
<a class="jxr_linenumber" name="71" href="#71">71</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/RemoveColumnAction.html">RemoveColumnAction</a>(tableName, columnFamilies),
<a class="jxr_linenumber" name="72" href="#72">72</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/ChangeEncodingAction.html">ChangeEncodingAction</a>(tableName),
<a class="jxr_linenumber" name="73" href="#73">73</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/ChangeCompressionAction.html">ChangeCompressionAction</a>(tableName),
<a class="jxr_linenumber" name="74" href="#74">74</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/ChangeBloomFilterAction.html">ChangeBloomFilterAction</a>(tableName),
<a class="jxr_linenumber" name="75" href="#75">75</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/ChangeVersionsAction.html">ChangeVersionsAction</a>(tableName),
<a class="jxr_linenumber" name="76" href="#76">76</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/ChangeSplitPolicyAction.html">ChangeSplitPolicyAction</a>(tableName),
<a class="jxr_linenumber" name="77" href="#77">77</a>      };
<a class="jxr_linenumber" name="78" href="#78">78</a>  
<a class="jxr_linenumber" name="79" href="#79">79</a>      <em class="jxr_comment">// Destructive actions to mess things around.</em>
<a class="jxr_linenumber" name="80" href="#80">80</a>      <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/Action.html">Action</a>[] actions3 = <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/Action.html">Action</a>[] {
<a class="jxr_linenumber" name="81" href="#81">81</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/MoveRegionsOfTableAction.html">MoveRegionsOfTableAction</a>(moveRegionsSleepTime, moveRegionsMaxTime,
<a class="jxr_linenumber" name="82" href="#82">82</a>              tableName),
<a class="jxr_linenumber" name="83" href="#83">83</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/MoveRandomRegionOfTableAction.html">MoveRandomRegionOfTableAction</a>(moveRandomRegionSleepTime, tableName),
<a class="jxr_linenumber" name="84" href="#84">84</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/RestartRandomRsAction.html">RestartRandomRsAction</a>(restartRandomRSSleepTime),
<a class="jxr_linenumber" name="85" href="#85">85</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/BatchRestartRsAction.html">BatchRestartRsAction</a>(batchRestartRSSleepTime, batchRestartRSRatio),
<a class="jxr_linenumber" name="86" href="#86">86</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/RestartActiveMasterAction.html">RestartActiveMasterAction</a>(restartActiveMasterSleepTime),
<a class="jxr_linenumber" name="87" href="#87">87</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/RollingBatchRestartRsAction.html">RollingBatchRestartRsAction</a>(rollingBatchRestartRSSleepTime,
<a class="jxr_linenumber" name="88" href="#88">88</a>              rollingBatchRestartRSRatio),
<a class="jxr_linenumber" name="89" href="#89">89</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/RestartRsHoldingMetaAction.html">RestartRsHoldingMetaAction</a>(restartRsHoldingMetaSleepTime),
<a class="jxr_linenumber" name="90" href="#90">90</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/DecreaseMaxHFileSizeAction.html">DecreaseMaxHFileSizeAction</a>(decreaseHFileSizeSleepTime, tableName),
<a class="jxr_linenumber" name="91" href="#91">91</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/SplitAllRegionOfTableAction.html">SplitAllRegionOfTableAction</a>(tableName),
<a class="jxr_linenumber" name="92" href="#92">92</a>      };
<a class="jxr_linenumber" name="93" href="#93">93</a>  
<a class="jxr_linenumber" name="94" href="#94">94</a>      <em class="jxr_comment">// Action to log more info for debugging</em>
<a class="jxr_linenumber" name="95" href="#95">95</a>      <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/Action.html">Action</a>[] actions4 = <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/Action.html">Action</a>[] {
<a class="jxr_linenumber" name="96" href="#96">96</a>          <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/actions/DumpClusterStatusAction.html">DumpClusterStatusAction</a>()
<a class="jxr_linenumber" name="97" href="#97">97</a>      };
<a class="jxr_linenumber" name="98" href="#98">98</a>  
<a class="jxr_linenumber" name="99" href="#99">99</a>      <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/monkies/PolicyBasedChaosMonkey.html">PolicyBasedChaosMonkey</a>(util,
<a class="jxr_linenumber" name="100" href="#100">100</a>         <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/policies/PeriodicRandomActionPolicy.html">PeriodicRandomActionPolicy</a>(action1Period, actions1),
<a class="jxr_linenumber" name="101" href="#101">101</a>         <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/policies/PeriodicRandomActionPolicy.html">PeriodicRandomActionPolicy</a>(action2Period, actions2),
<a class="jxr_linenumber" name="102" href="#102">102</a>         <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/policies/CompositeSequentialPolicy.html">CompositeSequentialPolicy</a>(
<a class="jxr_linenumber" name="103" href="#103">103</a>             <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/policies/DoActionsOncePolicy.html">DoActionsOncePolicy</a>(action3Period, actions3),
<a class="jxr_linenumber" name="104" href="#104">104</a>             <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/policies/PeriodicRandomActionPolicy.html">PeriodicRandomActionPolicy</a>(action3Period, actions3)),
<a class="jxr_linenumber" name="105" href="#105">105</a>         <strong class="jxr_keyword">new</strong> <a href="../../../../../../org/apache/hadoop/hbase/chaos/policies/PeriodicRandomActionPolicy.html">PeriodicRandomActionPolicy</a>(action4Period, actions4));
<a class="jxr_linenumber" name="106" href="#106">106</a>   }
<a class="jxr_linenumber" name="107" href="#107">107</a> 
<a class="jxr_linenumber" name="108" href="#108">108</a>   <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">void</strong> loadProperties() {
<a class="jxr_linenumber" name="109" href="#109">109</a> 
<a class="jxr_linenumber" name="110" href="#110">110</a>       action1Period = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="111" href="#111">111</a>         MonkeyConstants.PERIODIC_ACTION1_PERIOD,
<a class="jxr_linenumber" name="112" href="#112">112</a>         MonkeyConstants.DEFAULT_PERIODIC_ACTION1_PERIOD + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="113" href="#113">113</a>       action2Period = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="114" href="#114">114</a>         MonkeyConstants.PERIODIC_ACTION2_PERIOD,
<a class="jxr_linenumber" name="115" href="#115">115</a>         MonkeyConstants.DEFAULT_PERIODIC_ACTION2_PERIOD + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="116" href="#116">116</a>       action3Period = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="117" href="#117">117</a>         MonkeyConstants.COMPOSITE_ACTION3_PERIOD,
<a class="jxr_linenumber" name="118" href="#118">118</a>         MonkeyConstants.DEFAULT_COMPOSITE_ACTION3_PERIOD + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="119" href="#119">119</a>       action4Period = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="120" href="#120">120</a>         MonkeyConstants.PERIODIC_ACTION4_PERIOD,
<a class="jxr_linenumber" name="121" href="#121">121</a>         MonkeyConstants.DEFAULT_PERIODIC_ACTION4_PERIOD + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="122" href="#122">122</a>       moveRegionsMaxTime = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="123" href="#123">123</a>         MonkeyConstants.MOVE_REGIONS_MAX_TIME,
<a class="jxr_linenumber" name="124" href="#124">124</a>         MonkeyConstants.DEFAULT_MOVE_REGIONS_MAX_TIME + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="125" href="#125">125</a>       moveRegionsSleepTime = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="126" href="#126">126</a>         MonkeyConstants.MOVE_REGIONS_SLEEP_TIME,
<a class="jxr_linenumber" name="127" href="#127">127</a>         MonkeyConstants.DEFAULT_MOVE_REGIONS_SLEEP_TIME + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="128" href="#128">128</a>       moveRandomRegionSleepTime = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="129" href="#129">129</a>         MonkeyConstants.MOVE_RANDOM_REGION_SLEEP_TIME,
<a class="jxr_linenumber" name="130" href="#130">130</a>         MonkeyConstants.DEFAULT_MOVE_RANDOM_REGION_SLEEP_TIME + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="131" href="#131">131</a>       restartRandomRSSleepTime = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="132" href="#132">132</a>         MonkeyConstants.RESTART_RANDOM_RS_SLEEP_TIME,
<a class="jxr_linenumber" name="133" href="#133">133</a>         MonkeyConstants.DEFAULT_RESTART_RANDOM_RS_SLEEP_TIME + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="134" href="#134">134</a>       batchRestartRSSleepTime = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="135" href="#135">135</a>         MonkeyConstants.BATCH_RESTART_RS_SLEEP_TIME,
<a class="jxr_linenumber" name="136" href="#136">136</a>         MonkeyConstants.DEFAULT_BATCH_RESTART_RS_SLEEP_TIME + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="137" href="#137">137</a>       batchRestartRSRatio = Float.parseFloat(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="138" href="#138">138</a>         MonkeyConstants.BATCH_RESTART_RS_RATIO,
<a class="jxr_linenumber" name="139" href="#139">139</a>         MonkeyConstants.DEFAULT_BATCH_RESTART_RS_RATIO + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="140" href="#140">140</a>       restartActiveMasterSleepTime = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="141" href="#141">141</a>         MonkeyConstants.RESTART_ACTIVE_MASTER_SLEEP_TIME,
<a class="jxr_linenumber" name="142" href="#142">142</a>         MonkeyConstants.DEFAULT_RESTART_ACTIVE_MASTER_SLEEP_TIME + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="143" href="#143">143</a>       rollingBatchRestartRSSleepTime = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="144" href="#144">144</a>         MonkeyConstants.ROLLING_BATCH_RESTART_RS_SLEEP_TIME,
<a class="jxr_linenumber" name="145" href="#145">145</a>         MonkeyConstants.DEFAULT_ROLLING_BATCH_RESTART_RS_SLEEP_TIME + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="146" href="#146">146</a>       rollingBatchRestartRSRatio = Float.parseFloat(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="147" href="#147">147</a>         MonkeyConstants.ROLLING_BATCH_RESTART_RS_RATIO,
<a class="jxr_linenumber" name="148" href="#148">148</a>         MonkeyConstants.DEFAULT_ROLLING_BATCH_RESTART_RS_RATIO + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="149" href="#149">149</a>       restartRsHoldingMetaSleepTime = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="150" href="#150">150</a>         MonkeyConstants.RESTART_RS_HOLDING_META_SLEEP_TIME,
<a class="jxr_linenumber" name="151" href="#151">151</a>         MonkeyConstants.DEFAULT_RESTART_RS_HOLDING_META_SLEEP_TIME + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="152" href="#152">152</a>       compactTableRatio = Float.parseFloat(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="153" href="#153">153</a>         MonkeyConstants.COMPACT_TABLE_ACTION_RATIO,
<a class="jxr_linenumber" name="154" href="#154">154</a>         MonkeyConstants.DEFAULT_COMPACT_TABLE_ACTION_RATIO + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="155" href="#155">155</a>       compactRandomRegionRatio = Float.parseFloat(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="156" href="#156">156</a>         MonkeyConstants.COMPACT_RANDOM_REGION_RATIO,
<a class="jxr_linenumber" name="157" href="#157">157</a>         MonkeyConstants.DEFAULT_COMPACT_RANDOM_REGION_RATIO + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="158" href="#158">158</a>     decreaseHFileSizeSleepTime = Long.parseLong(<strong class="jxr_keyword">this</strong>.properties.getProperty(
<a class="jxr_linenumber" name="159" href="#159">159</a>         MonkeyConstants.DECREASE_HFILE_SIZE_SLEEP_TIME,
<a class="jxr_linenumber" name="160" href="#160">160</a>         MonkeyConstants.DEFAULT_DECREASE_HFILE_SIZE_SLEEP_TIME + <span class="jxr_string">""</span>));
<a class="jxr_linenumber" name="161" href="#161">161</a>   }
<a class="jxr_linenumber" name="162" href="#162">162</a> }
</pre>
<hr/><div id="footer">This page was automatically generated by <a href="http://maven.apache.org/">Maven</a></div></body>
</html>

