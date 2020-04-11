<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8" />
<title>ScanWildcardColumnTracker xref</title>
<link type="text/css" rel="stylesheet" href="../../../../../../stylesheet.css" />
</head>
<body>
<div id="overview"><a href="../../../../../../../apidocs/org/apache/hadoop/hbase/regionserver/querymatcher/ScanWildcardColumnTracker.html">View Javadoc</a></div><pre>

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
<a class="jxr_linenumber" name="19" href="#19">19</a>  <strong class="jxr_keyword">package</strong> org.apache.hadoop.hbase.regionserver.querymatcher;
<a class="jxr_linenumber" name="20" href="#20">20</a>  
<a class="jxr_linenumber" name="21" href="#21">21</a>  <strong class="jxr_keyword">import</strong> java.io.IOException;
<a class="jxr_linenumber" name="22" href="#22">22</a>  
<a class="jxr_linenumber" name="23" href="#23">23</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.CellUtil;
<a class="jxr_linenumber" name="24" href="#24">24</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.HConstants;
<a class="jxr_linenumber" name="25" href="#25">25</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.classification.InterfaceAudience;
<a class="jxr_linenumber" name="26" href="#26">26</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.regionserver.querymatcher.ScanQueryMatcher.MatchCode;
<a class="jxr_linenumber" name="27" href="#27">27</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.util.Bytes;
<a class="jxr_linenumber" name="28" href="#28">28</a>  
<a class="jxr_linenumber" name="29" href="#29">29</a>  <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="30" href="#30">30</a>  <em class="jxr_javadoccomment"> * Keeps track of the columns for a scan if they are not explicitly specified</em>
<a class="jxr_linenumber" name="31" href="#31">31</a>  <em class="jxr_javadoccomment"> */</em>
<a class="jxr_linenumber" name="32" href="#32">32</a>  @InterfaceAudience.Private
<a class="jxr_linenumber" name="33" href="#33">33</a>  <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">class</strong> <a href="../../../../../../org/apache/hadoop/hbase/regionserver/querymatcher/ScanWildcardColumnTracker.html">ScanWildcardColumnTracker</a> <strong class="jxr_keyword">implements</strong> <a href="../../../../../../org/apache/hadoop/hbase/regionserver/querymatcher/ColumnTracker.html">ColumnTracker</a> {
<a class="jxr_linenumber" name="34" href="#34">34</a>    <strong class="jxr_keyword">private</strong> byte[] columnBuffer = <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="35" href="#35">35</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">int</strong> columnOffset = 0;
<a class="jxr_linenumber" name="36" href="#36">36</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">int</strong> columnLength = 0;
<a class="jxr_linenumber" name="37" href="#37">37</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">int</strong> currentCount = 0;
<a class="jxr_linenumber" name="38" href="#38">38</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">int</strong> maxVersions;
<a class="jxr_linenumber" name="39" href="#39">39</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">int</strong> minVersions;
<a class="jxr_linenumber" name="40" href="#40">40</a>    <em class="jxr_comment">/*</em>
<a class="jxr_linenumber" name="41" href="#41">41</a>  <em class="jxr_comment">   * Keeps track of the latest timestamp and type included for current column. Used to eliminate</em>
<a class="jxr_linenumber" name="42" href="#42">42</a>  <em class="jxr_comment">   * duplicates.</em>
<a class="jxr_linenumber" name="43" href="#43">43</a>  <em class="jxr_comment">   */</em>
<a class="jxr_linenumber" name="44" href="#44">44</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> latestTSOfCurrentColumn;
<a class="jxr_linenumber" name="45" href="#45">45</a>    <strong class="jxr_keyword">private</strong> byte latestTypeOfCurrentColumn;
<a class="jxr_linenumber" name="46" href="#46">46</a>  
<a class="jxr_linenumber" name="47" href="#47">47</a>    <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">long</strong> oldestStamp;
<a class="jxr_linenumber" name="48" href="#48">48</a>  
<a class="jxr_linenumber" name="49" href="#49">49</a>    <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="50" href="#50">50</a>  <em class="jxr_javadoccomment">   * Return maxVersions of every row.</em>
<a class="jxr_linenumber" name="51" href="#51">51</a>  <em class="jxr_javadoccomment">   * @param minVersion Minimum number of versions to keep</em>
<a class="jxr_linenumber" name="52" href="#52">52</a>  <em class="jxr_javadoccomment">   * @param maxVersion Maximum number of versions to return</em>
<a class="jxr_linenumber" name="53" href="#53">53</a>  <em class="jxr_javadoccomment">   * @param oldestUnexpiredTS oldest timestamp that has not expired according to the TTL.</em>
<a class="jxr_linenumber" name="54" href="#54">54</a>  <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="55" href="#55">55</a>    <strong class="jxr_keyword">public</strong> <a href="../../../../../../org/apache/hadoop/hbase/regionserver/querymatcher/ScanWildcardColumnTracker.html">ScanWildcardColumnTracker</a>(<strong class="jxr_keyword">int</strong> minVersion, <strong class="jxr_keyword">int</strong> maxVersion, <strong class="jxr_keyword">long</strong> oldestUnexpiredTS) {
<a class="jxr_linenumber" name="56" href="#56">56</a>      <strong class="jxr_keyword">this</strong>.maxVersions = maxVersion;
<a class="jxr_linenumber" name="57" href="#57">57</a>      <strong class="jxr_keyword">this</strong>.minVersions = minVersion;
<a class="jxr_linenumber" name="58" href="#58">58</a>      <strong class="jxr_keyword">this</strong>.oldestStamp = oldestUnexpiredTS;
<a class="jxr_linenumber" name="59" href="#59">59</a>    }
<a class="jxr_linenumber" name="60" href="#60">60</a>  
<a class="jxr_linenumber" name="61" href="#61">61</a>    <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="62" href="#62">62</a>  <em class="jxr_javadoccomment">   * {@inheritDoc} This receives puts *and* deletes.</em>
<a class="jxr_linenumber" name="63" href="#63">63</a>  <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="64" href="#64">64</a>    @Override
<a class="jxr_linenumber" name="65" href="#65">65</a>    <strong class="jxr_keyword">public</strong> <a href="../../../../../../org/apache/hadoop/hbase/regionserver/querymatcher/ScanQueryMatcher.html">MatchCode</a> checkColumn(byte[] bytes, <strong class="jxr_keyword">int</strong> offset, <strong class="jxr_keyword">int</strong> length, byte type) <strong class="jxr_keyword">throws</strong> IOException {
<a class="jxr_linenumber" name="66" href="#66">66</a>      <strong class="jxr_keyword">return</strong> MatchCode.INCLUDE;
<a class="jxr_linenumber" name="67" href="#67">67</a>    }
<a class="jxr_linenumber" name="68" href="#68">68</a>  
<a class="jxr_linenumber" name="69" href="#69">69</a>    <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="70" href="#70">70</a>  <em class="jxr_javadoccomment">   * {@inheritDoc} This receives puts *and* deletes. Deletes do not count as a version, but rather</em>
<a class="jxr_linenumber" name="71" href="#71">71</a>  <em class="jxr_javadoccomment">   * take the version of the previous put (so eventually all but the last can be reclaimed).</em>
<a class="jxr_linenumber" name="72" href="#72">72</a>  <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="73" href="#73">73</a>    @Override
<a class="jxr_linenumber" name="74" href="#74">74</a>    <strong class="jxr_keyword">public</strong> ScanQueryMatcher.MatchCode checkVersions(byte[] bytes, <strong class="jxr_keyword">int</strong> offset, <strong class="jxr_keyword">int</strong> length,
<a class="jxr_linenumber" name="75" href="#75">75</a>        <strong class="jxr_keyword">long</strong> timestamp, byte type, <strong class="jxr_keyword">boolean</strong> ignoreCount) <strong class="jxr_keyword">throws</strong> IOException {
<a class="jxr_linenumber" name="76" href="#76">76</a>  
<a class="jxr_linenumber" name="77" href="#77">77</a>      <strong class="jxr_keyword">if</strong> (columnBuffer == <strong class="jxr_keyword">null</strong>) {
<a class="jxr_linenumber" name="78" href="#78">78</a>        <em class="jxr_comment">// first iteration.</em>
<a class="jxr_linenumber" name="79" href="#79">79</a>        resetBuffer(bytes, offset, length);
<a class="jxr_linenumber" name="80" href="#80">80</a>        <strong class="jxr_keyword">if</strong> (ignoreCount) {
<a class="jxr_linenumber" name="81" href="#81">81</a>          <strong class="jxr_keyword">return</strong> ScanQueryMatcher.MatchCode.INCLUDE;
<a class="jxr_linenumber" name="82" href="#82">82</a>        }
<a class="jxr_linenumber" name="83" href="#83">83</a>        <em class="jxr_comment">// do not count a delete marker as another version</em>
<a class="jxr_linenumber" name="84" href="#84">84</a>        <strong class="jxr_keyword">return</strong> checkVersion(type, timestamp);
<a class="jxr_linenumber" name="85" href="#85">85</a>      }
<a class="jxr_linenumber" name="86" href="#86">86</a>      <strong class="jxr_keyword">int</strong> cmp = Bytes.compareTo(bytes, offset, length, columnBuffer, columnOffset, columnLength);
<a class="jxr_linenumber" name="87" href="#87">87</a>      <strong class="jxr_keyword">if</strong> (cmp == 0) {
<a class="jxr_linenumber" name="88" href="#88">88</a>        <strong class="jxr_keyword">if</strong> (ignoreCount) {
<a class="jxr_linenumber" name="89" href="#89">89</a>          <strong class="jxr_keyword">return</strong> ScanQueryMatcher.MatchCode.INCLUDE;
<a class="jxr_linenumber" name="90" href="#90">90</a>        }
<a class="jxr_linenumber" name="91" href="#91">91</a>  
<a class="jxr_linenumber" name="92" href="#92">92</a>        <em class="jxr_comment">// If column matches, check if it is a duplicate timestamp</em>
<a class="jxr_linenumber" name="93" href="#93">93</a>        <strong class="jxr_keyword">if</strong> (sameAsPreviousTSAndType(timestamp, type)) {
<a class="jxr_linenumber" name="94" href="#94">94</a>          <strong class="jxr_keyword">return</strong> ScanQueryMatcher.MatchCode.SKIP;
<a class="jxr_linenumber" name="95" href="#95">95</a>        }
<a class="jxr_linenumber" name="96" href="#96">96</a>        <strong class="jxr_keyword">return</strong> checkVersion(type, timestamp);
<a class="jxr_linenumber" name="97" href="#97">97</a>      }
<a class="jxr_linenumber" name="98" href="#98">98</a>  
<a class="jxr_linenumber" name="99" href="#99">99</a>      resetTSAndType();
<a class="jxr_linenumber" name="100" href="#100">100</a> 
<a class="jxr_linenumber" name="101" href="#101">101</a>     <em class="jxr_comment">// new col &gt; old col</em>
<a class="jxr_linenumber" name="102" href="#102">102</a>     <strong class="jxr_keyword">if</strong> (cmp &gt; 0) {
<a class="jxr_linenumber" name="103" href="#103">103</a>       <em class="jxr_comment">// switched columns, lets do something.x</em>
<a class="jxr_linenumber" name="104" href="#104">104</a>       resetBuffer(bytes, offset, length);
<a class="jxr_linenumber" name="105" href="#105">105</a>       <strong class="jxr_keyword">if</strong> (ignoreCount) {
<a class="jxr_linenumber" name="106" href="#106">106</a>         <strong class="jxr_keyword">return</strong> ScanQueryMatcher.MatchCode.INCLUDE;
<a class="jxr_linenumber" name="107" href="#107">107</a>       }
<a class="jxr_linenumber" name="108" href="#108">108</a>       <strong class="jxr_keyword">return</strong> checkVersion(type, timestamp);
<a class="jxr_linenumber" name="109" href="#109">109</a>     }
<a class="jxr_linenumber" name="110" href="#110">110</a> 
<a class="jxr_linenumber" name="111" href="#111">111</a>     <em class="jxr_comment">// new col &lt; oldcol</em>
<a class="jxr_linenumber" name="112" href="#112">112</a>     <em class="jxr_comment">// WARNING: This means that very likely an edit for some other family</em>
<a class="jxr_linenumber" name="113" href="#113">113</a>     <em class="jxr_comment">// was incorrectly stored into the store for this one. Throw an exception,</em>
<a class="jxr_linenumber" name="114" href="#114">114</a>     <em class="jxr_comment">// because this might lead to data corruption.</em>
<a class="jxr_linenumber" name="115" href="#115">115</a>     <strong class="jxr_keyword">throw</strong> <strong class="jxr_keyword">new</strong> IOException(<span class="jxr_string">"ScanWildcardColumnTracker.checkColumn ran into a column actually "</span>
<a class="jxr_linenumber" name="116" href="#116">116</a>         + <span class="jxr_string">"smaller than the previous column: "</span> + Bytes.toStringBinary(bytes, offset, length));
<a class="jxr_linenumber" name="117" href="#117">117</a>   }
<a class="jxr_linenumber" name="118" href="#118">118</a> 
<a class="jxr_linenumber" name="119" href="#119">119</a>   <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">void</strong> resetBuffer(byte[] bytes, <strong class="jxr_keyword">int</strong> offset, <strong class="jxr_keyword">int</strong> length) {
<a class="jxr_linenumber" name="120" href="#120">120</a>     columnBuffer = bytes;
<a class="jxr_linenumber" name="121" href="#121">121</a>     columnOffset = offset;
<a class="jxr_linenumber" name="122" href="#122">122</a>     columnLength = length;
<a class="jxr_linenumber" name="123" href="#123">123</a>     currentCount = 0;
<a class="jxr_linenumber" name="124" href="#124">124</a>   }
<a class="jxr_linenumber" name="125" href="#125">125</a> 
<a class="jxr_linenumber" name="126" href="#126">126</a>   <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="127" href="#127">127</a> <em class="jxr_javadoccomment">   * Check whether this version should be retained. There are 4 variables considered: If this</em>
<a class="jxr_linenumber" name="128" href="#128">128</a> <em class="jxr_javadoccomment">   * version is past max versions -&gt; skip it If this kv has expired or was deleted, check min</em>
<a class="jxr_linenumber" name="129" href="#129">129</a> <em class="jxr_javadoccomment">   * versions to decide whther to skip it or not. Increase the version counter unless this is a</em>
<a class="jxr_linenumber" name="130" href="#130">130</a> <em class="jxr_javadoccomment">   * delete</em>
<a class="jxr_linenumber" name="131" href="#131">131</a> <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="132" href="#132">132</a>   <strong class="jxr_keyword">private</strong> <a href="../../../../../../org/apache/hadoop/hbase/regionserver/querymatcher/ScanQueryMatcher.html">MatchCode</a> checkVersion(byte type, <strong class="jxr_keyword">long</strong> timestamp) {
<a class="jxr_linenumber" name="133" href="#133">133</a>     <strong class="jxr_keyword">if</strong> (!CellUtil.isDelete(type)) {
<a class="jxr_linenumber" name="134" href="#134">134</a>       currentCount++;
<a class="jxr_linenumber" name="135" href="#135">135</a>     }
<a class="jxr_linenumber" name="136" href="#136">136</a>     <strong class="jxr_keyword">if</strong> (currentCount &gt; maxVersions) {
<a class="jxr_linenumber" name="137" href="#137">137</a>       <strong class="jxr_keyword">return</strong> ScanQueryMatcher.MatchCode.SEEK_NEXT_COL; <em class="jxr_comment">// skip to next col</em>
<a class="jxr_linenumber" name="138" href="#138">138</a>     }
<a class="jxr_linenumber" name="139" href="#139">139</a>     <em class="jxr_comment">// keep the KV if required by minversions or it is not expired, yet</em>
<a class="jxr_linenumber" name="140" href="#140">140</a>     <strong class="jxr_keyword">if</strong> (currentCount &lt;= minVersions || !isExpired(timestamp)) {
<a class="jxr_linenumber" name="141" href="#141">141</a>       setTSAndType(timestamp, type);
<a class="jxr_linenumber" name="142" href="#142">142</a>       <strong class="jxr_keyword">return</strong> ScanQueryMatcher.MatchCode.INCLUDE;
<a class="jxr_linenumber" name="143" href="#143">143</a>     } <strong class="jxr_keyword">else</strong> {
<a class="jxr_linenumber" name="144" href="#144">144</a>       <strong class="jxr_keyword">return</strong> MatchCode.SEEK_NEXT_COL;
<a class="jxr_linenumber" name="145" href="#145">145</a>     }
<a class="jxr_linenumber" name="146" href="#146">146</a> 
<a class="jxr_linenumber" name="147" href="#147">147</a>   }
<a class="jxr_linenumber" name="148" href="#148">148</a> 
<a class="jxr_linenumber" name="149" href="#149">149</a>   @Override
<a class="jxr_linenumber" name="150" href="#150">150</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> reset() {
<a class="jxr_linenumber" name="151" href="#151">151</a>     columnBuffer = <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="152" href="#152">152</a>     resetTSAndType();
<a class="jxr_linenumber" name="153" href="#153">153</a>   }
<a class="jxr_linenumber" name="154" href="#154">154</a> 
<a class="jxr_linenumber" name="155" href="#155">155</a>   <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">void</strong> resetTSAndType() {
<a class="jxr_linenumber" name="156" href="#156">156</a>     latestTSOfCurrentColumn = HConstants.LATEST_TIMESTAMP;
<a class="jxr_linenumber" name="157" href="#157">157</a>     latestTypeOfCurrentColumn = 0;
<a class="jxr_linenumber" name="158" href="#158">158</a>   }
<a class="jxr_linenumber" name="159" href="#159">159</a> 
<a class="jxr_linenumber" name="160" href="#160">160</a>   <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">void</strong> setTSAndType(<strong class="jxr_keyword">long</strong> timestamp, byte type) {
<a class="jxr_linenumber" name="161" href="#161">161</a>     latestTSOfCurrentColumn = timestamp;
<a class="jxr_linenumber" name="162" href="#162">162</a>     latestTypeOfCurrentColumn = type;
<a class="jxr_linenumber" name="163" href="#163">163</a>   }
<a class="jxr_linenumber" name="164" href="#164">164</a> 
<a class="jxr_linenumber" name="165" href="#165">165</a>   <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">boolean</strong> sameAsPreviousTSAndType(<strong class="jxr_keyword">long</strong> timestamp, byte type) {
<a class="jxr_linenumber" name="166" href="#166">166</a>     <strong class="jxr_keyword">return</strong> timestamp == latestTSOfCurrentColumn &amp;&amp; type == latestTypeOfCurrentColumn;
<a class="jxr_linenumber" name="167" href="#167">167</a>   }
<a class="jxr_linenumber" name="168" href="#168">168</a> 
<a class="jxr_linenumber" name="169" href="#169">169</a>   <strong class="jxr_keyword">private</strong> <strong class="jxr_keyword">boolean</strong> isExpired(<strong class="jxr_keyword">long</strong> timestamp) {
<a class="jxr_linenumber" name="170" href="#170">170</a>     <strong class="jxr_keyword">return</strong> timestamp &lt; oldestStamp;
<a class="jxr_linenumber" name="171" href="#171">171</a>   }
<a class="jxr_linenumber" name="172" href="#172">172</a> 
<a class="jxr_linenumber" name="173" href="#173">173</a>   <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="174" href="#174">174</a> <em class="jxr_javadoccomment">   * Used by matcher and scan/get to get a hint of the next column to seek to after checkColumn()</em>
<a class="jxr_linenumber" name="175" href="#175">175</a> <em class="jxr_javadoccomment">   * returns SKIP. Returns the next interesting column we want, or NULL there is none (wildcard</em>
<a class="jxr_linenumber" name="176" href="#176">176</a> <em class="jxr_javadoccomment">   * scanner).</em>
<a class="jxr_linenumber" name="177" href="#177">177</a> <em class="jxr_javadoccomment">   * @return The column count.</em>
<a class="jxr_linenumber" name="178" href="#178">178</a> <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="179" href="#179">179</a>   <strong class="jxr_keyword">public</strong> <a href="../../../../../../org/apache/hadoop/hbase/regionserver/querymatcher/ColumnCount.html">ColumnCount</a> getColumnHint() {
<a class="jxr_linenumber" name="180" href="#180">180</a>     <strong class="jxr_keyword">return</strong> <strong class="jxr_keyword">null</strong>;
<a class="jxr_linenumber" name="181" href="#181">181</a>   }
<a class="jxr_linenumber" name="182" href="#182">182</a> 
<a class="jxr_linenumber" name="183" href="#183">183</a>   <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="184" href="#184">184</a> <em class="jxr_javadoccomment">   * We can never know a-priori if we are done, so always return false.</em>
<a class="jxr_linenumber" name="185" href="#185">185</a> <em class="jxr_javadoccomment">   * @return false</em>
<a class="jxr_linenumber" name="186" href="#186">186</a> <em class="jxr_javadoccomment">   */</em>
<a class="jxr_linenumber" name="187" href="#187">187</a>   @Override
<a class="jxr_linenumber" name="188" href="#188">188</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">boolean</strong> done() {
<a class="jxr_linenumber" name="189" href="#189">189</a>     <strong class="jxr_keyword">return</strong> false;
<a class="jxr_linenumber" name="190" href="#190">190</a>   }
<a class="jxr_linenumber" name="191" href="#191">191</a> 
<a class="jxr_linenumber" name="192" href="#192">192</a>   <strong class="jxr_keyword">public</strong> <a href="../../../../../../org/apache/hadoop/hbase/regionserver/querymatcher/ScanQueryMatcher.html">MatchCode</a> getNextRowOrNextColumn(byte[] bytes, <strong class="jxr_keyword">int</strong> offset, <strong class="jxr_keyword">int</strong> qualLength) {
<a class="jxr_linenumber" name="193" href="#193">193</a>     <strong class="jxr_keyword">return</strong> MatchCode.SEEK_NEXT_COL;
<a class="jxr_linenumber" name="194" href="#194">194</a>   }
<a class="jxr_linenumber" name="195" href="#195">195</a> 
<a class="jxr_linenumber" name="196" href="#196">196</a>   <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">boolean</strong> isDone(<strong class="jxr_keyword">long</strong> timestamp) {
<a class="jxr_linenumber" name="197" href="#197">197</a>     <strong class="jxr_keyword">return</strong> minVersions &lt;= 0 &amp;&amp; isExpired(timestamp);
<a class="jxr_linenumber" name="198" href="#198">198</a>   }
<a class="jxr_linenumber" name="199" href="#199">199</a> }
</pre>
<hr/><div id="footer">This page was automatically generated by <a href="http://maven.apache.org/">Maven</a></div></body>
</html>

