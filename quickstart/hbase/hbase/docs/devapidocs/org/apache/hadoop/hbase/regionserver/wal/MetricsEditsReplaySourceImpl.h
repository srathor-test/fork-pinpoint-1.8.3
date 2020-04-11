<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<!-- NewPage -->
<html lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>MetricsEditsReplaySourceImpl (Apache HBase 1.4.13 API)</title>
<link rel="stylesheet" type="text/css" href="../../../../../../stylesheet.css" title="Style">
</head>
<body>
<script type="text/javascript"><!--
    try {
        if (location.href.indexOf('is-external=true') == -1) {
            parent.document.title="MetricsEditsReplaySourceImpl (Apache HBase 1.4.13 API)";
        }
    }
    catch(err) {
    }
//-->
</script>
<noscript>
<div>JavaScript is disabled on your browser.</div>
</noscript>
<!-- ========= START OF TOP NAVBAR ======= -->
<div class="topNav"><a name="navbar_top">
<!--   -->
</a><a href="#skip-navbar_top" title="Skip navigation links"></a><a name="navbar_top_firstrow">
<!--   -->
</a>
<ul class="navList" title="Navigation">
<li><a href="../../../../../../overview-summary.html">Overview</a></li>
<li><a href="package-summary.html">Package</a></li>
<li class="navBarCell1Rev">Class</li>
<li><a href="class-use/MetricsEditsReplaySourceImpl.html">Use</a></li>
<li><a href="package-tree.html">Tree</a></li>
<li><a href="../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html" title="interface in org.apache.hadoop.hbase.regionserver.wal"><span class="strong">Prev Class</span></a></li>
<li><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsWAL.html" title="class in org.apache.hadoop.hbase.regionserver.wal"><span class="strong">Next Class</span></a></li>
</ul>
<ul class="navList">
<li><a href="../../../../../../index.html?org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySourceImpl.html" target="_top">Frames</a></li>
<li><a href="MetricsEditsReplaySourceImpl.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_top">
<li><a href="../../../../../../allclasses-noframe.html">All Classes</a></li>
</ul>
<div>
<script type="text/javascript"><!--
  allClassesLink = document.getElementById("allclasses_navbar_top");
  if(window==top) {
    allClassesLink.style.display = "block";
  }
  else {
    allClassesLink.style.display = "none";
  }
  //-->
</script>
</div>
<div>
<ul class="subNavList">
<li>Summary:&nbsp;</li>
<li>Nested&nbsp;|&nbsp;</li>
<li><a href="#fields_inherited_from_class_org.apache.hadoop.hbase.metrics.BaseSourceImpl">Field</a>&nbsp;|&nbsp;</li>
<li><a href="#constructor_summary">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_summary">Method</a></li>
</ul>
<ul class="subNavList">
<li>Detail:&nbsp;</li>
<li>Field&nbsp;|&nbsp;</li>
<li><a href="#constructor_detail">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_detail">Method</a></li>
</ul>
</div>
<a name="skip-navbar_top">
<!--   -->
</a></div>
<!-- ========= END OF TOP NAVBAR ========= -->
<!-- ======== START OF CLASS DATA ======== -->
<div class="header">
<div class="subTitle">org.apache.hadoop.hbase.regionserver.wal</div>
<h2 title="Class MetricsEditsReplaySourceImpl" class="title">Class MetricsEditsReplaySourceImpl</h2>
</div>
<div class="contentContainer">
<ul class="inheritance">
<li><a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true" title="class or interface in java.lang">java.lang.Object</a></li>
<li>
<ul class="inheritance">
<li><a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html" title="class in org.apache.hadoop.hbase.metrics">org.apache.hadoop.hbase.metrics.BaseSourceImpl</a></li>
<li>
<ul class="inheritance">
<li>org.apache.hadoop.hbase.regionserver.wal.MetricsEditsReplaySourceImpl</li>
</ul>
</li>
</ul>
</li>
</ul>
<div class="description">
<ul class="blockList">
<li class="blockList">
<dl>
<dt>All Implemented Interfaces:</dt>
<dd><a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html" title="interface in org.apache.hadoop.hbase.metrics">BaseSource</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">MetricsEditsReplaySource</a>, org.apache.hadoop.metrics2.MetricsSource</dd>
</dl>
<hr>
<br>
<pre><a href="../../../../../../org/apache/hadoop/hbase/classification/InterfaceAudience.Private.html" title="annotation in org.apache.hadoop.hbase.classification">@InterfaceAudience.Private</a>
public class <span class="strong">MetricsEditsReplaySourceImpl</span>
extends <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html" title="class in org.apache.hadoop.hbase.metrics">BaseSourceImpl</a>
implements <a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">MetricsEditsReplaySource</a></pre>
<div class="block">Hadoop1 implementation of MetricsMasterSource. Implements BaseSource through BaseSourceImpl,
 following the pattern</div>
</li>
</ul>
</div>
<div class="summary">
<ul class="blockList">
<li class="blockList">
<!-- =========== FIELD SUMMARY =========== -->
<ul class="blockList">
<li class="blockList"><a name="field_summary">
<!--   -->
</a>
<h3>Field Summary</h3>
<ul class="blockList">
<li class="blockList"><a name="fields_inherited_from_class_org.apache.hadoop.hbase.metrics.BaseSourceImpl">
<!--   -->
</a>
<h3>Fields inherited from class&nbsp;org.apache.hadoop.hbase.metrics.<a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html" title="class in org.apache.hadoop.hbase.metrics">BaseSourceImpl</a></h3>
<code><a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#metricsAdapter">metricsAdapter</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#metricsContext">metricsContext</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#metricsDescription">metricsDescription</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#metricsJmxContext">metricsJmxContext</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#metricsName">metricsName</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#metricsRegistry">metricsRegistry</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#registry">registry</a></code></li>
</ul>
<ul class="blockList">
<li class="blockList"><a name="fields_inherited_from_class_org.apache.hadoop.hbase.regionserver.wal.MetricsEditsReplaySource">
<!--   -->
</a>
<h3>Fields inherited from interface&nbsp;org.apache.hadoop.hbase.regionserver.wal.<a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">MetricsEditsReplaySource</a></h3>
<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#METRICS_CONTEXT">METRICS_CONTEXT</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#METRICS_DESCRIPTION">METRICS_DESCRIPTION</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#METRICS_JMX_CONTEXT">METRICS_JMX_CONTEXT</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#METRICS_NAME">METRICS_NAME</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#REPLAY_BATCH_SIZE_DESC">REPLAY_BATCH_SIZE_DESC</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#REPLAY_BATCH_SIZE_NAME">REPLAY_BATCH_SIZE_NAME</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#REPLAY_DATA_SIZE_DESC">REPLAY_DATA_SIZE_DESC</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#REPLAY_DATA_SIZE_NAME">REPLAY_DATA_SIZE_NAME</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#REPLAY_TIME_DESC">REPLAY_TIME_DESC</a>, <a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#REPLAY_TIME_NAME">REPLAY_TIME_NAME</a></code></li>
</ul>
<ul class="blockList">
<li class="blockList"><a name="fields_inherited_from_class_org.apache.hadoop.hbase.metrics.BaseSource">
<!--   -->
</a>
<h3>Fields inherited from interface&nbsp;org.apache.hadoop.hbase.metrics.<a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html" title="interface in org.apache.hadoop.hbase.metrics">BaseSource</a></h3>
<code><a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#HBASE_METRICS_SYSTEM_NAME">HBASE_METRICS_SYSTEM_NAME</a></code></li>
</ul>
</li>
</ul>
<!-- ======== CONSTRUCTOR SUMMARY ======== -->
<ul class="blockList">
<li class="blockList"><a name="constructor_summary">
<!--   -->
</a>
<h3>Constructor Summary</h3>
<table class="overviewSummary" border="0" cellpadding="3" cellspacing="0" summary="Constructor Summary table, listing constructors, and an explanation">
<caption><span>Constructors</span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colOne" scope="col">Constructor and Description</th>
</tr>
<tr class="altColor">
<td class="colOne"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySourceImpl.html#MetricsEditsReplaySourceImpl()">MetricsEditsReplaySourceImpl</a></strong>()</code>&nbsp;</td>
</tr>
<tr class="rowColor">
<td class="colOne"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySourceImpl.html#MetricsEditsReplaySourceImpl(java.lang.String,%20java.lang.String,%20java.lang.String,%20java.lang.String)">MetricsEditsReplaySourceImpl</a></strong>(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;metricsName,
                            <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;metricsDescription,
                            <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;metricsContext,
                            <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;metricsJmxContext)</code>&nbsp;</td>
</tr>
</table>
</li>
</ul>
<!-- ========== METHOD SUMMARY =========== -->
<ul class="blockList">
<li class="blockList"><a name="method_summary">
<!--   -->
</a>
<h3>Method Summary</h3>
<table class="overviewSummary" border="0" cellpadding="3" cellspacing="0" summary="Method Summary table, listing methods, and an explanation">
<caption><span>Methods</span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Method and Description</th>
</tr>
<tr class="altColor">
<td class="colFirst"><code>void</code></td>
<td class="colLast"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySourceImpl.html#init()">init</a></strong>()</code>
<div class="block">Clear out the metrics and re-prepare the source.</div>
</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>void</code></td>
<td class="colLast"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySourceImpl.html#updateReplayBatchSize(long)">updateReplayBatchSize</a></strong>(long&nbsp;size)</code>
<div class="block">Add the batch size of each replay</div>
</td>
</tr>
<tr class="altColor">
<td class="colFirst"><code>void</code></td>
<td class="colLast"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySourceImpl.html#updateReplayDataSize(long)">updateReplayDataSize</a></strong>(long&nbsp;size)</code>
<div class="block">Add the payload data size of each replay</div>
</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>void</code></td>
<td class="colLast"><code><strong><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySourceImpl.html#updateReplayTime(long)">updateReplayTime</a></strong>(long&nbsp;time)</code>
<div class="block">Add the time a replay command took</div>
</td>
</tr>
</table>
<ul class="blockList">
<li class="blockList"><a name="methods_inherited_from_class_org.apache.hadoop.hbase.metrics.BaseSourceImpl">
<!--   -->
</a>
<h3>Methods inherited from class&nbsp;org.apache.hadoop.hbase.metrics.<a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html" title="class in org.apache.hadoop.hbase.metrics">BaseSourceImpl</a></h3>
<code><a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#decGauge(java.lang.String,%20long)">decGauge</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#getMetricRegistryInfo()">getMetricRegistryInfo</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#getMetrics(org.apache.hadoop.metrics2.MetricsCollector,%20boolean)">getMetrics</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#getMetricsContext()">getMetricsContext</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#getMetricsDescription()">getMetricsDescription</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#getMetricsJmxContext()">getMetricsJmxContext</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#getMetricsName()">getMetricsName</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#getMetricsRegistry()">getMetricsRegistry</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#incCounters(java.lang.String,%20long)">incCounters</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#incGauge(java.lang.String,%20long)">incGauge</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#removeMetric(java.lang.String)">removeMetric</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#setGauge(java.lang.String,%20long)">setGauge</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#updateHistogram(java.lang.String,%20long)">updateHistogram</a></code></li>
</ul>
<ul class="blockList">
<li class="blockList"><a name="methods_inherited_from_class_java.lang.Object">
<!--   -->
</a>
<h3>Methods inherited from class&nbsp;java.lang.<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true" title="class or interface in java.lang">Object</a></h3>
<code><a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#clone()" title="class or interface in java.lang">clone</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#equals(java.lang.Object)" title="class or interface in java.lang">equals</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#finalize()" title="class or interface in java.lang">finalize</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#getClass()" title="class or interface in java.lang">getClass</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#hashCode()" title="class or interface in java.lang">hashCode</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#notify()" title="class or interface in java.lang">notify</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#notifyAll()" title="class or interface in java.lang">notifyAll</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#toString()" title="class or interface in java.lang">toString</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#wait()" title="class or interface in java.lang">wait</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#wait(long)" title="class or interface in java.lang">wait</a>, <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/Object.html?is-external=true#wait(long,%20int)" title="class or interface in java.lang">wait</a></code></li>
</ul>
<ul class="blockList">
<li class="blockList"><a name="methods_inherited_from_class_org.apache.hadoop.hbase.metrics.BaseSource">
<!--   -->
</a>
<h3>Methods inherited from interface&nbsp;org.apache.hadoop.hbase.metrics.<a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html" title="interface in org.apache.hadoop.hbase.metrics">BaseSource</a></h3>
<code><a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#decGauge(java.lang.String,%20long)">decGauge</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#getMetricRegistryInfo()">getMetricRegistryInfo</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#getMetricsContext()">getMetricsContext</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#getMetricsDescription()">getMetricsDescription</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#getMetricsJmxContext()">getMetricsJmxContext</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#getMetricsName()">getMetricsName</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#incCounters(java.lang.String,%20long)">incCounters</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#incGauge(java.lang.String,%20long)">incGauge</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#removeMetric(java.lang.String)">removeMetric</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#setGauge(java.lang.String,%20long)">setGauge</a>, <a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#updateHistogram(java.lang.String,%20long)">updateHistogram</a></code></li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
<div class="details">
<ul class="blockList">
<li class="blockList">
<!-- ========= CONSTRUCTOR DETAIL ======== -->
<ul class="blockList">
<li class="blockList"><a name="constructor_detail">
<!--   -->
</a>
<h3>Constructor Detail</h3>
<a name="MetricsEditsReplaySourceImpl()">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>MetricsEditsReplaySourceImpl</h4>
<pre>public&nbsp;MetricsEditsReplaySourceImpl()</pre>
</li>
</ul>
<a name="MetricsEditsReplaySourceImpl(java.lang.String, java.lang.String, java.lang.String, java.lang.String)">
<!--   -->
</a>
<ul class="blockListLast">
<li class="blockList">
<h4>MetricsEditsReplaySourceImpl</h4>
<pre>public&nbsp;MetricsEditsReplaySourceImpl(<a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;metricsName,
                            <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;metricsDescription,
                            <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;metricsContext,
                            <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;metricsJmxContext)</pre>
</li>
</ul>
</li>
</ul>
<!-- ============ METHOD DETAIL ========== -->
<ul class="blockList">
<li class="blockList"><a name="method_detail">
<!--   -->
</a>
<h3>Method Detail</h3>
<a name="init()">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>init</h4>
<pre>public&nbsp;void&nbsp;init()</pre>
<div class="block"><strong>Description copied from interface:&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#init()">BaseSource</a></code></strong></div>
<div class="block">Clear out the metrics and re-prepare the source.</div>
<dl>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html#init()">init</a></code>&nbsp;in interface&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSource.html" title="interface in org.apache.hadoop.hbase.metrics">BaseSource</a></code></dd>
<dt><strong>Overrides:</strong></dt>
<dd><code><a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html#init()">init</a></code>&nbsp;in class&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/metrics/BaseSourceImpl.html" title="class in org.apache.hadoop.hbase.metrics">BaseSourceImpl</a></code></dd>
</dl>
</li>
</ul>
<a name="updateReplayTime(long)">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>updateReplayTime</h4>
<pre>public&nbsp;void&nbsp;updateReplayTime(long&nbsp;time)</pre>
<div class="block"><strong>Description copied from interface:&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#updateReplayTime(long)">MetricsEditsReplaySource</a></code></strong></div>
<div class="block">Add the time a replay command took</div>
<dl>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#updateReplayTime(long)">updateReplayTime</a></code>&nbsp;in interface&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">MetricsEditsReplaySource</a></code></dd>
</dl>
</li>
</ul>
<a name="updateReplayBatchSize(long)">
<!--   -->
</a>
<ul class="blockList">
<li class="blockList">
<h4>updateReplayBatchSize</h4>
<pre>public&nbsp;void&nbsp;updateReplayBatchSize(long&nbsp;size)</pre>
<div class="block"><strong>Description copied from interface:&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#updateReplayBatchSize(long)">MetricsEditsReplaySource</a></code></strong></div>
<div class="block">Add the batch size of each replay</div>
<dl>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#updateReplayBatchSize(long)">updateReplayBatchSize</a></code>&nbsp;in interface&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">MetricsEditsReplaySource</a></code></dd>
</dl>
</li>
</ul>
<a name="updateReplayDataSize(long)">
<!--   -->
</a>
<ul class="blockListLast">
<li class="blockList">
<h4>updateReplayDataSize</h4>
<pre>public&nbsp;void&nbsp;updateReplayDataSize(long&nbsp;size)</pre>
<div class="block"><strong>Description copied from interface:&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#updateReplayDataSize(long)">MetricsEditsReplaySource</a></code></strong></div>
<div class="block">Add the payload data size of each replay</div>
<dl>
<dt><strong>Specified by:</strong></dt>
<dd><code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html#updateReplayDataSize(long)">updateReplayDataSize</a></code>&nbsp;in interface&nbsp;<code><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html" title="interface in org.apache.hadoop.hbase.regionserver.wal">MetricsEditsReplaySource</a></code></dd>
</dl>
</li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
</div>
<!-- ========= END OF CLASS DATA ========= -->
<!-- ======= START OF BOTTOM NAVBAR ====== -->
<div class="bottomNav"><a name="navbar_bottom">
<!--   -->
</a><a href="#skip-navbar_bottom" title="Skip navigation links"></a><a name="navbar_bottom_firstrow">
<!--   -->
</a>
<ul class="navList" title="Navigation">
<li><a href="../../../../../../overview-summary.html">Overview</a></li>
<li><a href="package-summary.html">Package</a></li>
<li class="navBarCell1Rev">Class</li>
<li><a href="class-use/MetricsEditsReplaySourceImpl.html">Use</a></li>
<li><a href="package-tree.html">Tree</a></li>
<li><a href="../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySource.html" title="interface in org.apache.hadoop.hbase.regionserver.wal"><span class="strong">Prev Class</span></a></li>
<li><a href="../../../../../../org/apache/hadoop/hbase/regionserver/wal/MetricsWAL.html" title="class in org.apache.hadoop.hbase.regionserver.wal"><span class="strong">Next Class</span></a></li>
</ul>
<ul class="navList">
<li><a href="../../../../../../index.html?org/apache/hadoop/hbase/regionserver/wal/MetricsEditsReplaySourceImpl.html" target="_top">Frames</a></li>
<li><a href="MetricsEditsReplaySourceImpl.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_bottom">
<li><a href="../../../../../../allclasses-noframe.html">All Classes</a></li>
</ul>
<div>
<script type="text/javascript"><!--
  allClassesLink = document.getElementById("allclasses_navbar_bottom");
  if(window==top) {
    allClassesLink.style.display = "block";
  }
  else {
    allClassesLink.style.display = "none";
  }
  //-->
</script>
</div>
<div>
<ul class="subNavList">
<li>Summary:&nbsp;</li>
<li>Nested&nbsp;|&nbsp;</li>
<li><a href="#fields_inherited_from_class_org.apache.hadoop.hbase.metrics.BaseSourceImpl">Field</a>&nbsp;|&nbsp;</li>
<li><a href="#constructor_summary">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_summary">Method</a></li>
</ul>
<ul class="subNavList">
<li>Detail:&nbsp;</li>
<li>Field&nbsp;|&nbsp;</li>
<li><a href="#constructor_detail">Constr</a>&nbsp;|&nbsp;</li>
<li><a href="#method_detail">Method</a></li>
</ul>
</div>
<a name="skip-navbar_bottom">
<!--   -->
</a></div>
<!-- ======== END OF BOTTOM NAVBAR ======= -->
<p class="legalCopy"><small>Copyright &#169; 2007&#x2013;2020 <a href="https://www.apache.org/">The Apache Software Foundation</a>. All rights reserved.</small></p>
</body>
</html>
