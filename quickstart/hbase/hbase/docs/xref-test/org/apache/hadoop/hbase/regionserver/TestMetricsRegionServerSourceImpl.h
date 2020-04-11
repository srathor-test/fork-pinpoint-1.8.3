<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8" />
<title>TestMetricsRegionServerSourceImpl xref</title>
<link type="text/css" rel="stylesheet" href="../../../../../stylesheet.css" />
</head>
<body>
<div id="overview"><a href="../../../../../../testapidocs/org/apache/hadoop/hbase/regionserver/TestMetricsRegionServerSourceImpl.html">View Javadoc</a></div><pre>

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
<a class="jxr_linenumber" name="19" href="#19">19</a>  <strong class="jxr_keyword">package</strong> org.apache.hadoop.hbase.regionserver;
<a class="jxr_linenumber" name="20" href="#20">20</a>  
<a class="jxr_linenumber" name="21" href="#21">21</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.CompatibilitySingletonFactory;
<a class="jxr_linenumber" name="22" href="#22">22</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.testclassification.SmallTests;
<a class="jxr_linenumber" name="23" href="#23">23</a>  <strong class="jxr_keyword">import</strong> org.apache.hadoop.hbase.testclassification.MetricsTests;
<a class="jxr_linenumber" name="24" href="#24">24</a>  <strong class="jxr_keyword">import</strong> org.junit.Test;
<a class="jxr_linenumber" name="25" href="#25">25</a>  <strong class="jxr_keyword">import</strong> org.junit.experimental.categories.Category;
<a class="jxr_linenumber" name="26" href="#26">26</a>  
<a class="jxr_linenumber" name="27" href="#27">27</a>  <strong class="jxr_keyword">import</strong> <strong class="jxr_keyword">static</strong> org.junit.Assert.assertSame;
<a class="jxr_linenumber" name="28" href="#28">28</a>  <strong class="jxr_keyword">import</strong> <strong class="jxr_keyword">static</strong> org.junit.Assert.assertTrue;
<a class="jxr_linenumber" name="29" href="#29">29</a>  
<a class="jxr_linenumber" name="30" href="#30">30</a>  <em class="jxr_javadoccomment">/**</em>
<a class="jxr_linenumber" name="31" href="#31">31</a>  <em class="jxr_javadoccomment"> *  Test for MetricsRegionServerSourceImpl</em>
<a class="jxr_linenumber" name="32" href="#32">32</a>  <em class="jxr_javadoccomment"> */</em>
<a class="jxr_linenumber" name="33" href="#33">33</a>  @Category({MetricsTests.<strong class="jxr_keyword">class</strong>, SmallTests.<strong class="jxr_keyword">class</strong>})
<a class="jxr_linenumber" name="34" href="#34">34</a>  <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">class</strong> <a href="../../../../../org/apache/hadoop/hbase/regionserver/TestMetricsRegionServerSourceImpl.html">TestMetricsRegionServerSourceImpl</a> {
<a class="jxr_linenumber" name="35" href="#35">35</a>  
<a class="jxr_linenumber" name="36" href="#36">36</a>    @Test
<a class="jxr_linenumber" name="37" href="#37">37</a>    <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> testGetInstance() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="38" href="#38">38</a>      MetricsRegionServerSourceFactory metricsRegionServerSourceFactory =
<a class="jxr_linenumber" name="39" href="#39">39</a>          CompatibilitySingletonFactory.getInstance(MetricsRegionServerSourceFactory.<strong class="jxr_keyword">class</strong>);
<a class="jxr_linenumber" name="40" href="#40">40</a>      MetricsRegionServerSource serverSource =
<a class="jxr_linenumber" name="41" href="#41">41</a>          metricsRegionServerSourceFactory.createServer(<strong class="jxr_keyword">null</strong>);
<a class="jxr_linenumber" name="42" href="#42">42</a>      assertTrue(serverSource instanceof MetricsRegionServerSourceImpl);
<a class="jxr_linenumber" name="43" href="#43">43</a>      assertSame(metricsRegionServerSourceFactory,
<a class="jxr_linenumber" name="44" href="#44">44</a>          CompatibilitySingletonFactory.getInstance(MetricsRegionServerSourceFactory.<strong class="jxr_keyword">class</strong>));
<a class="jxr_linenumber" name="45" href="#45">45</a>    }
<a class="jxr_linenumber" name="46" href="#46">46</a>  
<a class="jxr_linenumber" name="47" href="#47">47</a>  
<a class="jxr_linenumber" name="48" href="#48">48</a>    @Test(expected = RuntimeException.<strong class="jxr_keyword">class</strong>)
<a class="jxr_linenumber" name="49" href="#49">49</a>    <strong class="jxr_keyword">public</strong> <strong class="jxr_keyword">void</strong> testNoGetRegionServerMetricsSourceImpl() <strong class="jxr_keyword">throws</strong> Exception {
<a class="jxr_linenumber" name="50" href="#50">50</a>      <em class="jxr_comment">// This should throw an exception because MetricsRegionServerSourceImpl should only</em>
<a class="jxr_linenumber" name="51" href="#51">51</a>      <em class="jxr_comment">// be created by a factory.</em>
<a class="jxr_linenumber" name="52" href="#52">52</a>      CompatibilitySingletonFactory.getInstance(MetricsRegionServerSourceImpl.<strong class="jxr_keyword">class</strong>);
<a class="jxr_linenumber" name="53" href="#53">53</a>    }
<a class="jxr_linenumber" name="54" href="#54">54</a>  }
</pre>
<hr/><div id="footer">This page was automatically generated by <a href="http://maven.apache.org/">Maven</a></div></body>
</html>

